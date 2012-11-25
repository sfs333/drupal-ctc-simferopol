*******************************************************************************
                     D R U P A L    M O D U L E
*******************************************************************************
Name: Highslide 2
Author: jpnova
Drupal: 7.x
*******************************************************************************

NOTE: This is a port of the Highslide module implementation in
      Drupal 7 with enhancement and modification.

DESCRIPTION:

This module implements Highslide JS, an open source image, media and 
gallery viewer written in JavaScript.

For example, you can create gallery of images that automatically starts.

There are different ways of using it:
  You can enable highslide to display the images of every link pointing to an 
    image.
  You can use it with the image module (present in the core)
  You can activate it only on selected images by placing a class="highslide" in
    in the anchor's link.
  You can also bypass every setting and directly code the highslide directives
    in the HTML code.

Highslide JS provides so many different settings and lay-out that it was
almost impossible to implement all of them. But to allow you to do it you can
copy/paste the customized settings from the highslide editor into the module.
*******************************************************************************

INSTALLATION:

1. Copy the higslide2 module into sites/all/modules/highslide2
    or install it with the Drupal add modules functionality.
    
2. Download Highslide JS from http://highlside.com 
    you must include the graphics folder and copy it into the highslide folder 
    in sites/all/modules/highslide2.
    
    There are different java script available on the Highslide site, I recommend 
    using one of the full version (in order of preference 
    'highslide-full.min.js', 'highslide-full.packed.js' or 'highslide-full.js').
    If you download other version of the script, be aware that some of the 
    features/options available in the module settings could not work.

3. Enable the  module by navigating to:

     Administer > Modules

4. If you want anyone besides the administrative user to be able
   to configure highslide, they must be given
   the "administer highslide" access permission:
   
     Administer > User management > Access control

   When the module is enabled and the user has the "administer
   highslide" permission, an "highslide" menu should appear under 
   Administer > Site configuration > Media.

*******************************************************************************

USAGE:
Configuration 
  The configuration is divided in two parts, the settings that will be applied 
  globally and the formatters that will be used on the different node types with
  the images.  
  There is always a default formatter which can be customized but cannot be 
  deleted.
  
  Most of the times, you'll use the default formatter for all the site, but if 
  you need different effects, you can create more than one formatter.
  Except for the default formatter (which is always applied), the other 
  formatters can only be applied on the image type field.
  
  
Settings customization
  Highslide JS provide an editor to customize and test the behavior and the 
  lay-out.
  If you can't obtain the behavior/lay-out you want through the settings in 
  this module, you can adapt it by copying the CSS and the JS produced by the 
  Highslide editor into the customize fields in the settings.

Modes
  You can use Highslide2 in different ways depending of you needs:
1.	Full automatic
  Activate “Enable for all image links” option in the settings.
  With this options, all the links pointing to an image (jpg, png or gif) will 
  be automatically serviced by Highslide. The default formatter will be used to
  manage the lay-out and the behavior.
  
2.	With the image field
  Go to Administer > Structure > Content Type  and choose  manage display. 
  For image field you can choose 'highslide2' under format, you  will have to 
  specify a few parameters:
    The formatter you want to use, 
    Image style : This is the image style used on the node
    Linked to   : is the image style that will be displayed by Highslide JS
    Heading and Caption : what will be the source text for the heading and/or
      the caption (if you have chosen to show one of those in the formatter).
      You can use the alt attribute or the title attribute of the image field
      (this must be activated in the image field), the node title or the alt 
      attribute of the anchor (this one is for advanced users).
  You can use different formatters to configure different node type (you have to 
  create those in the formatter section of the settings).
  
3.	Add class=”highslide” in the anchor
  If you want to activate Highslide to a specific image, you can do so by adding
  the class=”highslide” in the image anchor’s tag.
  The default formatter will be used to manage the lay-out and the behavior.
  
4.  On your own
  You can also fully customize Highslide (see http://Highslide.com) and let this
  module load the needed scripts and CSS. But in this case, I think you don’t 
  need this module to do the job :-)