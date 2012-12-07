<?php
/**
 * @file
 * Zen theme's implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['navigation']: Items for the navigation region, below the main menu (if any).
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['footer']: Items for the footer region.
 * - $page['bottom']: Items to appear at the bottom of the page below the footer.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see zen_preprocess_page()
 * @see template_process()
 */
?>
<?php if(drupal_is_front_page()): ?>
  <?php drupal_add_js(drupal_get_path('theme', 'ctc') . '/js/tonningimage.js');?>
<?php endif; ?>

<div id="site">
    <div id="hader">
        <!--        <a id="logo" href="http://ctc" title="Домой">-->
        <!--            <img src="/public/theme/images/logo.png?964"/>-->
        <!--        </a>-->

	   <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Домой'); ?>" rel="home" id="logo">
            <img src="<?php print $logo; ?>" alt="<?php print t('Домой'); ?>"/>
        </a>
	   <?php endif; ?>

	   <?php if ($site_slogan): ?>
        <div id="slogan" style="color:#2e4b19">
            <p><?php print $site_slogan; ?></p>
        </div>
	   <?php endif; ?>

        <div class="hader">
		   <?php if ($main_menu): ?>
		   <?php print theme('links__system_main_menu', array(
			  'links' => $main_menu,
			  'attributes' => array('id' => 'menu')
		   )); ?>
		   <?php endif; ?>

		   <?php if ($site_name): ?>
            <div id="sitename" style="color:#c3cd55">
                <h1><?php print $site_name; ?></h1>
            </div>
		   <?php endif; ?>

        </div>
    </div>

   <?php print $messages; ?>
<!--   --><?php //dsm($test11); ?>
   <?php if ($page['slide_top']): ?>
    <div id="">
	   <?php print render($page['slide_top']); ?>
    </div>
   <?php endif; ?>

  <?php if ($breadcrumb): ?>
    <div id="breadcrumb">
        <?php print $breadcrumb; ?>
    </div>
  <?php endif; ?>

   <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
  <?php if (!drupal_is_front_page()): ?>
      <?php print $title; ?>
  <?php endif; ?>
   <?php if ($page['content']): ?>
    <div id="content">
	   <?php print render($page['content']); ?>
    </div>
   <?php endif; ?>

    <div id="bottom">
        <div class="headBottom">
        </div>
        <div class="tel">Телефоны для справок:
            <?php if (!empty($tell_company)): ?>
            <?php foreach($tell_company as $tell): ?>
              <div class="item-tell"><?php print $tell['value']; ?></div>
            <?php endforeach; ?>
            <?php endif; ?>
<!--            print $tell['value'];-->
        </div>
    </div>
</div>


 


