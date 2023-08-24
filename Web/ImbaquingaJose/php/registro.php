<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];
    $email = $_POST['email'];
	$cedula=$_POST['cedula'];
	$f_nac=$_POST['f_n'];
	$civil=$_POST['civil'];
	$cargas=$_POST['cargas'];
	$sueldo=$_POST['sueldo'];

    // Lee el archivo de usuarios existente
    $users = file("usuarios.txt", FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

    // Verifica si el correo, usuario o contraseña ya están registrados
    foreach ($users as $user) {
        list($existingUsername, $existingPassword, $existingEmail) = explode(':', $user);
        if ($username === $existingUsername) {
            die("El nombre de usuario '$username' ya ha sido registrado. Intente con otro.");
        }
        if ($email === $existingEmail) {
            die("El correo electrónico '$email' ya ha sido registrado. Intente con otro.");
        }
    }

    // Abre el archivo en modo escritura y crea uno nuevo si no existe
    $file = fopen("usuarios.txt", "a");

    // Escribe los datos en el archivo
    fwrite($file, $username . ":" . $password . ":" . $email . ":".$cedula.":".$cargas.":".$civil.":".$sueldo.":".$f_nac."\n");

    // Cierra el archivo
    fclose($file);
    echo '<script>alert("Registro exitoso. ¡Bienvenido, '.$username.'!");</script>';
}

}
?>
