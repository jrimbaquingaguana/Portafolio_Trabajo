<?php
// Datos quemados para fines de demostración
$usuarios = array(
    array("Jose", "1234"),
    array("Ricardo", "1234"),
    // Puedes agregar más usuarios aquí
);

// Obtener los datos del formulario
if (isset($_POST['username']) && isset($_POST['password'])) {
    $usuario = $_POST['username'];
    $contrasena = $_POST['password'];

    // Verificar las credenciales
    $credenciales_validas = false;
    foreach ($usuarios as $user) {
        if ($user[0] === $usuario && $user[1] === $contrasena) {
            $credenciales_validas = true;
            break;
        }
    }

    // Redireccionar a otro archivo si las credenciales son válidas
    if ($credenciales_validas) {
        header("Location: ../html/prueba.html");
        exit;
    } else {
        // Mostrar un mensaje de error si las credenciales son inválidas
        echo "Credenciales inválidas. Inténtalo de nuevo.";
    }
}
?>