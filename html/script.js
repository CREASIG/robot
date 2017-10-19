/*
 * Paramètres
 */

var avancer = 0;
var reculer = 0;
var gauche = 0;
var droite = 0;


$(document).ready(function () {

 $.fn.avancer=function() {
    avancer = 10;
}

$.fn.gauche=function() {
    gauche = 10;
}

$.fn.droite=function() {
    droite = 10;
}

$.fn.reculer=function() {
    reculer = 10;
}


    
    $(this).keydown(function (e) {
        //bas
        switch (e.keyCode) {
            case 38:
                $.fn.avancer();
                break;
            case 37:
                $.fn.gauche();
                break;
            case 39:
                $.fn.droite();
                break;
            case 40:
                $.fn.reculer();
                break;
        }
    });

    $("#avancer").click(function () {
        $.fn.avancer();
    });
    $("#gauche").click(function () {
        $.fn.gauche();
    });
    $("#droite").click(function () {
        $.fn.droite();
    });
    $("#reculer").click(function () {
        $.fn.reculer();
    });


    $(function () {


        setInterval(function () {

            if (avancer !== 0 || reculer !== 0 || gauche !== 0 || droite !== 0) {
                $.ajax({
                    method: "POST",
                    url: "setparameter.php",
                    data: {
                        "avancer": avancer,
                        "reculer": reculer,
                        "gauche": gauche,
                        "droite": droite,
                    }
                }).done(function (msg) {
                    //alert("Data Saved: " + msg);
                    avancer = reculer = droite = gauche = 0;
                });
            }
        }, 1000);
    });

    $("#debug").click(function () {
        $.ajax({
            method: "POST",
            url: "debug.php",
            data: {}
        }).done(function (msg) {
            log = JSON.parse(msg);
            console.log(log["liste"]);
            var texte = "";
            for (var i = 0; i < log["liste"].length; i++) {
                texte += log["liste"][i]["texte"] + "\n";
            }
            console.log(texte);
            $("#log1").html(texte);
        });
    });


});