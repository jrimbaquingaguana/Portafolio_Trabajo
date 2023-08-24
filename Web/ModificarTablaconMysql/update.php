<?php
$db = new PDO('mysql:host=localhost;dbname=prueba2', 'jose', '040500');

if(isset($_POST["valor"])){
    $nombre = $_POST["nombre"];
    $apellido = $_POST["apellido"];
    $telefono = $_POST["telefono"];
    
    $documentos = implode(", ", $_POST["documentos"]);
    $direccion = $_POST["direccion"];  

    $upSent = $db->prepare("INSERT INTO `clientes`(`nombre`, `apellido`, `telefono`, `documentos`, `direccion`)
    VALUES (:nombre, :apellido, :telefono, :documentos, :direccion)");
    
    $upSent->bindParam(':nombre', $nombre);
    $upSent->bindParam(':apellido', $apellido);
    $upSent->bindParam(':telefono', $telefono);
    $upSent->bindParam(':documentos', $documentos);
    $upSent->bindParam(':direccion', $direccion);  
    
    $upSent->execute();
    
    if ($upSent->rowCount() > 0){
        echo 1;
    } else {
        echo 0;
    }
}
?>
