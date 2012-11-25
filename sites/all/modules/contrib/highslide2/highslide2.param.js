(function ($) {
  Drupal.behaviors.Highslide = {
    attach: function(context, settings) {

      if (settings.highslide2.options.autoEnableAllImages == 1) {
        $("a[href$='jpg'], a[href$='png'], a[href$='gif'], a[href$='jpeg'], a[href$='bmp'], a[href$='JPG'], a[href$='PNG'], a[href$='GIF'], a[href$='JPEG'], a[href$='BMP']").each(function() {
          if ($(this).attr('class') == '') {
            $(this).attr('class', 'highslide');
          }
        });
      }

      $('a.highslide').each(function() {
        this.onclick = function() {
          return hs.expand(this);
        }
      });

      $('a.highslide-html-link').click(function() {
        var href = $(this).attr('href');
        href = href.substr(1, href.length - 1);
        return hs.htmlExpand(this, {
            contentId: href,
            anchor: 'auto',
            outlineType: 'rounded-white',
            outlineWhileAnimating: true
          }
        );
      });
       $('a.highslide-ajax-link, a.highslide-ajax-link-wide').each(function() {
        this.onclick = function () {
          return hs.htmlExpand(this
          );
        }
      });
      $('.highslide-close').each(function() {
        this.onclick = function() {
          return hs.close(this);
        }
      });

      var highslidesettings = settings.highslide2.options;
      hs.transitions = ['expand', 'crossfade'];
      hs.graphicsDir = highslidesettings.graphicsDir;
      hs.align = highslidesettings.align;
      hs.outlineType = highslidesettings.outlineType;
      hs.allowMultipleInstances = (highslidesettings.allowMultipleInstances==1);

      hs.showCredits = highslidesettings.showCredits;
      hs.creditsHref = highslidesettings.credits.creditsHref;
      hs.creditsTitle = highslidesettings.credits.creditsTitle;
      hs.creditsPosition = highslidesettings.credits.creditsPosition;
      hs.creditsTarget = highslidesettings.credits.creditsTarget;
      hs.lang.creditsText = highslidesettings.credits.creditsText;

      if (highslidesettings.showDimming == 1 ) {
        hs.dimmingOpacity = highslidesettings.dimming.dimmingOpacity;
        hs.dimmingDuration = highslidesettings.dimming.dimmingDuration;
      }

      hs.expandDuration = 300;
      hs.marginLeft = 35;
      hs.marginRight = 35;
      hs.marginTop = 30;
      hs.marginBottom = 20;
      hs.numberOfImagesToPreload = 5;
      hs.captionSlideSpeed = 0;
      hs.spaceForCaption = 60;
      hs.easing = 'easeOutQuad';
      hs.easingClose = 'easeInQuad';
      hs.fadeInOut = true;

      hs.registerOverlay({
        html: '<div class="closebutton" onclick="return hs.close(this)" title="Close"></div>',
        position: 'top right',
        useOnHtml: true,
        fade: 2 // fading the semi-transparent overlay looks bad in IE
      });

      hs.numberPosition= highslidesettings.numberPosition;

      if (highslidesettings.showHeading == 1 ) {
        if (settings.highslide2.options.autoEnableAllImages == 1) {
          hs.headingEval = highslidesettings.enableAllImages.heading;
        } else {
          hs.headingEval = highslidesettings.heading.sourceText;
        }
        var headingPosition
        if (highslidesettings.heading.relativeTo == 'viewport') {
          headingPosition = highslidesettings.heading.positionViewport;
        } else {
          headingPosition = highslidesettings.heading.positionImage;
        }
        hs.headingOverlay.position = headingPosition;
        hs.headingOverlay.relativeTo = highslidesettings.heading.relativeTo;
      }

      if (highslidesettings.showCaption == 1 ) {
        if (settings.highslide2.options.autoEnableAllImages == 1) {
          hs.captionEval = highslidesettings.enableAllImages.caption;
        } else {
          hs.captionEval = highslidesettings.caption.sourceText;
        }        var captionPosition
        if (highslidesettings.caption.relativeTo == 'viewport') {
          captionPosition = highslidesettings.caption.positionViewport;
        } else {
          captionPosition = highslidesettings.caption.positionImage;
        }
        hs.captionOverlay.position = captionPosition;
        hs.captionOverlay.relativeTo = highslidesettings.caption.relativeTo;
      }

      if (highslidesettings.activateSlideshow == 1 ) {
        hs.autoplay = highslidesettings.slideshow.autoPlay;
        var thumbstrip
        if (highslidesettings.slideshow.showThumbstrip == 1 ) {
          var thumbstripPosition
          if (highslidesettings.slideshow.thumbstrip.relativeTo == 'viewport') {
            thumbstripPosition = highslidesettings.slideshow.thumbstrip.positionViewport;
          } else {
            thumbstripPosition = highslidesettings.slideshow.thumbstrip.positionImage;
          }

          thumbstrip = {
              mode: highslidesettings.slideshow.thumbstrip.mode,
              position: thumbstripPosition,
              relativeTo: highslidesettings.slideshow.thumbstrip.relativeTo
            }
        }


        var contolsPosition
        if (highslidesettings.slideshow.controls.relativeTo == 'viewport') {
          contolsPosition = highslidesettings.slideshow.controls.positionViewport;
        } else {
          contolsPosition = highslidesettings.slideshow.controls.positionImage;
        }

        var fixedControls
        if (highslidesettings.slideshow.fixedControls == 1) {
          fixedControls = 'fit';
        } else {
          fixedControls = false;
        }

        // Add the slideshow providing the controlbar and the thumbstrip
        hs.addSlideshow({
          //slideshowGroup: 'group1',
          interval: highslidesettings.slideshow.interval,
          repeat: (highslidesettings.slideshow.repeat==1),
          useControls: (highslidesettings.slideshow.useControls==1),
          fixedControls: fixedControls,
          overlayOptions: {
            className: highslidesettings.slideshow.controls.controlsClass,
            position: contolsPosition,
            relativeTo: highslidesettings.slideshow.controls.relativeTo,
            opacity: 0.6,
            offsetX: 50,
            offsetY: -5,
            hideOnMouseOut: (highslidesettings.slideshow.controls.hideOnMouseOut==1)
          },
          thumbstrip: thumbstrip
        });
      }
    }
  };
})(jQuery);
