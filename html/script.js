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

});