<!DOCTYPE html>
<html lang="jp">
<head>
    <meta charset="UTF-8">
    <title>24-22126-西山颯-Webプログラミング-PHP</title>
</head>
<body>
<?php
    echo date('<\p>今日はY年n月d日</p>');
    echo '<br>';
    echo '<br>';
    echo date('<\p>現在の時刻はH時i分s秒</p>');
?>

<form name="form" id="form" action="" method="POST">
    <label for="id">ID</label>
    <input name="id" id="id" type="text" value="">
    <label for="pass">PASSWORD</label>
    <input name="pass" id="pass" type="password" value="">
    <input type="submit" name="regist" value="登録">
    <input type="submit" name="auth" value="認証">
    <input type="submit" name="del" value="削除">
</form>

<?php
    if (isset($_POST['regist'])){
        if (empty($_POST['id']) || empty($_POST['pass'])){
            echo '未入力のため登録せず';
        } else {
            $id = $_POST['id'];
            $pass = $_POST['pass'];
            $conn = mysqli_connect("172.23.205.150", "pi", "raspberry", "jikken");
            $result = mysqli_query($conn, "SELECT * FROM web WHERE ID='$id';");
            if (mysqli_num_rows($result)==0){
                mysqli_query($conn, "INSERT INTO web VALUES (NULL, '$id', '$pass');");
                echo $id.'の登録完了';
            } else {
                echo $id.'の登録失敗';
            }
            mysqli_close($conn);
        }
    }

    if (isset($_POST['auth'])){
        $id = $_POST['id'];
        $pass = $_POST['pass'];
        $conn = mysqli_connect("172.23.205.150", "pi", "raspberry", "jikken");
        $result = mysqli_query($conn, "SELECT * FROM web WHERE ID='$id' AND PASSWORD='$pass';");
        if (mysqli_num_rows($result)!=0){
            echo $id.'の認証成功';
        } else {
            echo $id.'の認証失敗';
        }
        mysqli_close($conn);
    }

    if (isset($_POST['del'])){
        $id = $_POST['id'];
        $pass = $_POST['pass'];
        $conn = mysqli_connect("172.23.205.150", "pi", "raspberry", "jikken");
        $result = mysqli_query($conn, "SELECT * FROM web WHERE ID='$id' AND PASSWORD='$pass';");
        if (mysqli_num_rows($result)==0){
            echo $id.'の削除失敗';
        } else {
            mysqli_query($conn, query: "DELETE FROM web WHERE ID='$id';");
            echo $id.'の削除成功';
        }
        mysqli_close($conn);

    }
?>

</body>
</html>