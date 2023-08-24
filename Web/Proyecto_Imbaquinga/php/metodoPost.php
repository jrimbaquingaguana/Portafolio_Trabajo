<meta charset="utf-8">
<head>
	<title>Ejemplo de POST</title>
</head>
<body background="../img/fonfo2.jpg">
	<center>
		<br>
		<h1>Datos registrados tras usar el Método Post</h1>
		<?php

$nombre=$_POST['nombre'];
$edad=$_POST['edad'];
$dni=$_POST['dni'];
$apellidos=$_POST['apellidos'];
$domicilio=$_POST['domicilio'];
$postal=$_POST['postal'];
$localidad=$_POST['localidad'];
$provincia=$_POST['provincia'];
$telefono=$_POST['telefono'];
$coment=$_POST['coment'];

echo("El nombre de usuario: ".$nombre."<br>");
echo("La edad del usuario: ".$edad."<br>");
echo("El DNI: ".$dni."<br>");
echo("Los apellidos del usuario: ".$apellidos."<br>");
echo("El domicilio del usuario: ".$domicilio."<br>");
echo("El código postal del usuario: ".$postal."<br>");
echo("La localidad: ".$localidad."<br>");
echo("La provincia: ".$provincia."<br>");
echo("El teléfono del usuario: ".$telefono."<br>");
echo("Comentario registrado: ".$coment."<br>");
?>
</center>