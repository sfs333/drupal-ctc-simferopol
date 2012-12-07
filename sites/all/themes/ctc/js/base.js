

var toningImages = false;
(function($) {

    toningImages = function(images, hoverObj, callback) {
        callback = callback || function() {};
        if ($.browser.msie) {
            callback();
            return;
        }

        var loads = 0
        var lengImg = images.length;

        images.load(function(){
            $(this).jToningImage({
                color: "grey"
            });

            loads++;
            if (loads >= lengImg) callback();
        });

        hoverObj.hover(function(){
                $(this).find('.toiningImgNew').fadeOut(200);
            },
            function(){
                $(this).find('.toiningImgNew').fadeIn(200);
            });
    }

    $(document).ready(function() {

       $('#block-menu-menu-front-page-menu ul li a').each(function() {

           var bacground = $(this).css('background-image');
           if (bacground) {
               var href = bacground.substring(4, (bacground.length - 1));
               if (href && href.length > 6) {
                   var text = $(this).text();
                   $(this).text('')
                          .append($('<img src=' + href + ' />'))//.attr('src', href))
                          .append($('<div></div>').text(text))
                          .css('background', 'none')
                          .addClass('categor');
               }
           }
       })

        toningImages($(".categor img"), $(".categor"), function() {
            //$("#block-menu-menu-front-page-menu").css({'background':'none'}).find(".categor").fadeIn(700);
        });


    })

}) (jQuery)
