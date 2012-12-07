<div class="map-contact-popup">
  <?php print render($logo); ?>
  <div class="map-contact-popup-description">
      <strong><?php print $vars['site_name']; ?></strong>
      <br>
      <?php print $vars['site_slogan']; ?>
      <br>
      <br> Мы находимся по адрессу <br/>
      <?php print $vars['address_company']; ?>
      <br> тел: <?php print $vars['tell_company'][0]['value']; ?>
  </div>
</div>