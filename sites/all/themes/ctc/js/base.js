(function($) {

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
    })

}) (jQuery)
