
<?php if($teaser): ?>

<?php //foreach($content['field_label_album'] as $node): ?>
   <?php //var_dump($node); ?>
	<?php print render($content['field_label_album']); ?>
<?php //endforeach; ?>

<?php else: ?>

<script type="text/javascript">
    hs.graphicsDir = Drupal.settings.basePath + 'sites/all/themes/ctc/images/graphics/';
    hs.align = 'center';
    hs.transitions = ['expand', 'fade'];
    hs.fadeInOut = true;
    hs.dimmingOpacity = 0.8;
    hs.outlineType = 'rounded-white';
    hs.captionEval = 'this.thumb.alt';
    hs.marginBottom = 105; // make room for the thumbstrip and the controls
    hs.numberPosition = 'caption';

    // Add the slideshow providing the controlbar and the thumbstrip
    hs.addSlideshow({
        //slideshowGroup: 'group1',
        interval: 5000,
        repeat: true,
        useControls: true,
        overlayOptions: {
            className: 'text-controls',
            position: 'bottom center',
            relativeTo: 'viewport',
            offsetY: -60
        },
        thumbstrip: {
            position: 'bottom center',
            mode: 'horizontal',
            relativeTo: 'viewport'
        }
    });

</script>

<?php foreach ($content['field_album_photo'][0]['#items'] as &$item): ?>

   	<?php $item['path']['options']['attributes']['onclick'] = 'return hs.expand(this)'; ?>

<?php endforeach; ?>

<?php print $title; ?>
<?php print render($content['field_album_photo']); ?>
<?php print render($content['body']); ?>

<?php endif; ?>