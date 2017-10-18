/*
 * Paramètres
 */

var avancer = 0;
var reculer = 0;
var gauche = 0;
var droite = 0;


$(document).ready(function () {
    $(this).keydown(function (e) {
        //bas
        switch (e.keyCode) {
            case 38:
                avancer();
                break;
            case 37:
                gauche();
                break;
            case 39:
                droite();
                break;
            case 40:
                reculer();
                break;
        }
    });

    $("#avancer").click(function () {
        avancer = 10;
        console.log("avncer");
    });
    $("#gauche").click(function () {
        gauche = 10;
    });
    $("#droite").click(function () {
        droite = 10;
    });
    $("#reculer").click(function () {
        droite = 10;
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
        },1000);
    });

    $("#debug").click(function () {
        $.ajax({
            method: "POST",
            url: "debug.php",
            data: {name: "John"}
        })
                .done(function (msg) {
                    console.log(msg);
                    log = JSON.parse(msg);
                    console.log(log["liste"]);
                    var texte = "";
                    for (var i = 0; i < log["liste"].length; i++) {
                        texte += log["liste"][i]["texte"] + "\n";
                    }
                    console.log(texte);
                    $("#log").html(texte);
                });
        console.log("avancer");
    });


});