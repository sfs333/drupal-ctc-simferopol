<?php

function excel_reader_field_formatter_info() {
  $formatters = array(
    'excel' => array(
      'label' => t('Excel'),
      'field types' => array('file'),
//      'settings'    => array(
//        'slideshow_image_style'               => '',
//        'slideshow_link'                      => '',
//        'slideshow_colorbox_image_style'      => '',
//        'slideshow_colorbox_slideshow'        => '',
//        'slideshow_colorbox_slideshow_speed'  => '4000',
//        'slideshow_colorbox_transition'       => 'elastic',
//        'slideshow_colorbox_speed'            => '350',
//        'slideshow_caption'                   => '',
//        'slideshow_caption_link'              => '',
//        'slideshow_fx'                        => 'fade',
//        'slideshow_speed'                     => '1000',
//        'slideshow_timeout'                   => '4000',
//        'slideshow_order'                     => '',
//        'slideshow_controls'                  => 0,
//        'slideshow_controls_pause'            => 0,
//        'slideshow_controls_position'         => 'after',
//        'slideshow_pause'                     => 0,
//        'slideshow_start_on_hover'            => 0,
//        'slideshow_pager'                     => '',
//        'slideshow_pager_position'            => 'after',
//        'slideshow_pager_image_style'         => '',
//        'slideshow_carousel_image_style'      => '',
//        'slideshow_carousel_visible'          => '3',
//        'slideshow_carousel_scroll'           => '1',
//        'slideshow_carousel_speed'            => '500',
//        'slideshow_carousel_vertical'         => 0,
//        'slideshow_carousel_circular'         => 0,
//        'slideshow_carousel_follow'           => 0,
//        'slideshow_field_collection_image'    => '',
//      ),
    ),
  );
  return $formatters;
}

function excel_reader_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {

  $element = array();

  // Processing format types.
  switch ($display['type']) {
    case 'excel':

      foreach ($items as $delta => $item) {
        // If we have item then.
        if ($item['uri']) {


          // require_once drupal_get_path('module', 'excel_reader') . '/lib/excel_reader2.php';
          //$data->dump($row_numbers=false,$col_letters=false,$sheet=0,$table_class='excel');
          // $data = new Spreadsheet_Excel_Reader(drupal_realpath($item['uri']));
          ///$data = get_excel_table(drupal_realpath($item['uri']), 0, false, false, true, true);
          // Show text with tags.

          $element[$delta]['#markup'] = '<div>' . getXLS(drupal_realpath($item['uri'])) . '</div >';
        }
      }
      break;
  }
  return $element;

}


/**
 * Implements hook_field_is_empty().
 */
function excel_reader_is_empty($item, $field) {
  // If there's nothing in $item['textf'].
  if (empty($item['file'])) {
    // Then we return 1, i.e. we say to Drupal that everything is fine).
    return TRUE;
    // And if it's empty, nothing will be displayed.
  }
}

function parse_coordinate($coordinate) {

  preg_match("/^[A-Z]{0,}/i", $coordinate, $res);

  if (!empty($res[0])) {
    $outout['col'] = $res[0];
    $outout['row'] = substr($coordinate, strlen($res[0]));
    return $outout;
  }

  return FALSE;
}


//Функция принимает имя xls файла, считывает его, занося данные ячеек строк в массив, и возвращает этот массыв как результат
function getXLS($xls) {
  $worksheet = 1;
  require_once (drupal_get_path('module', 'excel_reader') . '/lib/Classes/PHPExcel/IOFactory.php');
  $inputFileType = PHPExcel_IOFactory::identify($xls);
  $objReader = PHPExcel_IOFactory::createReader($inputFileType);
  $objPHPExcel = $objReader->load($xls);
  $objWorksheet = $objPHPExcel->setActiveSheetIndex($worksheet);

  $rows = array();

  foreach ($objWorksheet->getRowIterator() as $row) {

    $cellIterator = $row->getCellIterator();
    $cellIterator->setIterateOnlyExistingCells(FALSE);

    foreach ($cellIterator as $cell) {
      $coordinate = parse_coordinate($cell->getCoordinate());
      if (!empty($coordinate['col']) && !empty($coordinate['row'])) {
        $rows[$coordinate['row']]['data'][$coordinate['col']] = array(
          'data' => $cell->getValue(),
        );
      }
    }
  }

  //merge cell
  foreach ($objWorksheet->getMergeCells() as $merge_diapozone) {

    $coordinates = explode(':', $merge_diapozone);
    $co_1 = parse_coordinate($coordinates[0]);
    $co_2 = parse_coordinate($coordinates[1]);

    //merge row
    if ($co_1['col'] == $co_2['col']) {
      $content = '';
      for ($i = $co_1['row']; $i <= $co_2['row']; $i++) {

        $content .= $rows[$i]['data'][$co_1['col']]['data'];

        if ($i != $co_1['row']) {
          unset ($rows[$i]['data'][$co_1['col']]);
        }
      }

      $rows[$co_1['row']]['data'][$co_1['col']]['data'] = $content;
      $rows[$co_1['row']]['data'][$co_1['col']]['rowspan'] = $i - (int) $co_1['row'];
    }
    //merge col
    if ($co_1['row'] == $co_2['row']) {

      $rowmerge = $rows[$co_1['row']]['data'];
      $clear = FALSE;
      $content = '';
      $colspan = 0;
      //dsm($rowmerge);

      do {

        $key = key($rowmerge);

        if ($key == $co_1['col']) {
          $clear = TRUE;
        }

        if ($clear) {

          $content .= $rowmerge[$key]['data'];
          if ($co_1['col'] != $key) {
            unset ($rows[$co_1['row']]['data'][$key]);
          }

          $colspan++;
        }

        next($rowmerge);

      } while ($key != $co_2['col']);

      $rows[$co_1['row']]['data'][$co_1['col']]['data'] = $content;
      $rows[$co_1['row']]['data'][$co_1['col']]['colspan'] = $colspan;

    }
  }


  $table = array(
    '#theme' => 'table',
    '#rows' => $rows,

  );


return render($table);






}


