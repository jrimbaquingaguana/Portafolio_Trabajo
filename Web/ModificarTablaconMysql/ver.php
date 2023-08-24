<?php
include('config.php');
require_once('config.php');



?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Tabla Usuarios</title>
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Roboto|Varela+Round">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    <link rel="stylesheet" href="css/estiloindex.css">

    <script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js"></script>
<style>
    /* Estilo para las filas desactivadas */
    .disabled-row {
        background-color:blue !important;
        color:red !important;

    }
</style>

</head>

<body>
    <div class="container-xl">
        <div class="table-responsive">
            <div class="table-wrapper">
                <div class="table-title">
                    <div class="row">
                        <div class="col-sm-5">
                            <h2>Administrador de <b>Clientes</b></h2>
                        </div>
                        <div class="col-md-4">
                <a href="index.php" class="btn btn-primary btn-block">Ingresar Usuarios!</a>
            </div>
                    </div>
                </div>
                <table class="table table-striped table-hover">
                    <thead>
                        <tr>
                            <th>#</th>
                            <th>Id </th>
                            <th>Nombre </th>
                            <th>Apellido </th>
                            <th>Telefono </th>
                            <th>Documentos que tiene</th>
                            <th>Dirrecion</th>
                            
                            
                        </tr>
                    </thead>
                    <tbody>
                    <?php
                
                
                    $cnt = 1;
                    $query = "SELECT * FROM clientes";
                    $stmt = $db->query($query);
                    
                    $results = $stmt->fetchAll();
                    
                    foreach ($results as $row) {
                        $usuarioID = $row['id'];

                ?>
                            <tr class="<?php echo $fila_clase; ?>">
                            <td><?php echo $cnt; ?></td>
                            <td><?php echo $row['id']; ?></td>
                            <td><?php echo $row['nombre']; ?></td>
                            <td><?php echo $row['apellido']; ?></td>
                            <td><?php echo $row['telefono']; ?></td>
                            <td><?php echo $row['documentos']; ?></td>
                            <td><?php echo $row['direccion']; ?></td>
                            <td>
                                <!-- Código adicional si es necesario -->
                            </td>
                        </tr>
                       
                <?php
                    }
               ?>

                    </tbody>
                </table>

            </div>
        </div>
    </div>

    
   



   
    
</body>

</html>
