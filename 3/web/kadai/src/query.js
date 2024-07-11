$(function () {
    // メニューを非表示
    $(".ddmenu li ul").css("display", "none");
    // マウスオーバー
    $(".ddmenutitle").hover(function () {
        // マウスオーバーした要素の取得
        var i = $(".ddmenutitle").index(this);
        // 取得した要素をスライドダウン
        $(".ddmenu li ul").eq(i).stop(true).slideDown("slow");
    }, function () {
        // その逆
        var i = $(".ddmenutitle").index(this);
        $(".ddmenu li ul").eq(i).stop(true).slideUp("slow");
    });
});
