<?php drupal_add_js('https://maps.google.com/maps/api/js?sensor=false'); ?>
<?php drupal_add_js(drupal_get_path('module', 'ctc') . '/map.js'); ?>

<div id="contact_page">
    <div id="contact_adress">
        <strong><div style="width:70px; float: left">Адресс:</div></strong>
        <?php print $address_company; ?>
        <br>
        <strong><div style="width:70px; float: left">Тел:</div></strong>

          <?php $tell_company_ln = count($tell_company) - 1; ?>
          <?php foreach($tell_company as $key => $tell): ?>
            <?php print $tell['value']; ?>
            <?php print ($tell_company_ln != (int)$key) ? ', ' : ''; ?>
          <?php endforeach; ?>

        <br>
        <strong><div style="width:70px; float: left">Факс:</div></strong>
          <?php $fax_company_ln = count($fax_company) - 1; ?>
          <?php foreach($fax_company as $key => $fax): ?>
             <?php print $fax['value']; ?>

            <?php print ($fax_company_ln != (int)$key) ? ', ' : ''; ?>

          <?php endforeach; ?>

        <br>
        <strong><div style="width:70px; float: left">e-mail:</div></strong><?php print $site_mail; ?><br>
    </div>
    <div id="contact_map_contener">
        <h3>Мы на карте</h3>
        <div id="contact_map"></div>
    </div>

    <div id="contact_form">
        <h3 style="text-align: center;">Напишете нам</h3>
        <?php print render($form); ?>
    </div>
</div>

