(function($) {
    $(document).ready(function() {

        var location;
        if (location = Drupal.settings.ctc.company_location) {
            var latlng = new google.maps.LatLng(location.lat, location.lng);
            console.log(Drupal.settings.ctc);
            var myOptions = {
                zoom: 16,
                center: latlng,
                mapTypeId: google.maps.MapTypeId.ROADMAP
            };
            var map = new google.maps.Map(document.getElementById("contact_map"), myOptions);


            var infowindow = new google.maps.InfoWindow({
                content: Drupal.settings.ctc.company_pop_up_map
            });

            var marker = new google.maps.Marker({
                position: latlng,
                title:Drupal.settings.ctc.site_name + " - " + Drupal.settings.ctc.site_slogan,
                map: map,
                icon: Drupal.settings.basePath + 'sites/all/modules/custom/ctc/images/marker.png',
                animation: google.maps.Animation.DROP
            });

            google.maps.event.addListener(marker, 'click', function() {
                infowindow.open(map, marker);
            });
        }
    });

}) (jQuery)