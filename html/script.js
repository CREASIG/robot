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
        avancer();
    });
    $("#gauche").click(function () {
        gauche();
    });
    $("#droite").click(function () {
        droite();
    });
    $("#reculer").click(function () {
        reculer();
    });

    function avancer() {
        $.ajax({
            method: "POST",
            url: "setparameter.php",
            data: {name: "John", location: "Boston"}
        })
                .done(function (msg) {
                    //alert("Data Saved: " + msg);
                });
        console.log("avancer");
    }
    function droite() {
        console.log("droite");
    }
    function gauche() {
        console.log("gauche");
    }
    function reculer() {
        console.log("reculer");
    }

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
                    var texte="";
                    for(var i = 0 ; i < log["liste"].length ; i++){
                        texte+=log["liste"][i]["texte"]+"\n";
                    }
                    console.log(texte);
                    $("#log").html(texte);
                });
        console.log("avancer");
    });


});