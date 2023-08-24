<!DOCTYPE html>
<html lang="en">
<head>
    <title>Registrar clientes</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
    <script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
</head>
<body>
<div class="container">
    <form action="">
        <div class="row">
            <div class="col-md-4">
                <h2 style="text-align: center;">Registrar clientes</h2>
            </div>
        </div>

        <div class="row">
            <div class="col-md-4">
                <label for="nombre">Nombre</label>
                <input type="text" name="nombre" id="nombre" class="form-control">
            </div>
            <div class="col-md-4">
                <label for="apellido">Apellido</label>
                <input type="text" name="apellido" id="apellido" class="form-control">
            </div>
        </div>
        <div class="row">
            <div class="col-md-4">
                <label for="telefono">Telefono</label>
                <input type="text" name="telefono" id="telefono" class="form-control">
            </div>

            <div class="row">
                <div class="col-md-4">
                    <label for="direccion">Dirección</label>
                    <select name="direccion" id="direccion" class="form-control">
                        <option value="12 Octubre">12 Octubre</option>
                        <option value="La Patria">La Patria</option>
                        <option value="9 Octubre">9 Octubre</option>
                    </select>
                </div>
            </div>

        </div>

        <fieldset>
            <legend>Documentos</legend>
            <div class="row">
                <div class="col-md-4">
                    <label><input type="checkbox" name="documentos[]" value="Copia cedula"> Copia cedula</label><br>
                    <label><input type="checkbox" name="documentos[]" value="Fotografia"> Fotografia</label><br>
                    <label><input type="checkbox" name="documentos[]" value="Partida nacimeinto"> Partida nacimiento</label><br>
                    <label><input type="checkbox" name="documentos[]" value="Copia pasaporte"> Copia pasaporte</label><br>
                    <label><input type="checkbox" name="documentos[]" value="Visa"> Visa</label><br>
                </div>
            </div>
        </fieldset>

        <br>
        <div class="row">
            <div class="col-md-4">
                <button id="upSubmit" type="button" class="btn btn-primary btn-block">Registrar!</button>
            </div>
            <div class="col-md-4">
                <a href="ver.php" class="btn btn-primary btn-block">Ver Registros!</a>
            </div>
        </div>
        <br>
        <div class="row">
            <div class="col-md-4">
                <span class="text-danger align-middle" id="Msg"></span>
            </div>
        </div>
    </form>
   
</div>

<script type="text/javascript">
    $(document).ready(function(){
        $(document).on("click","#upSubmit", function(){
            var valor = "update";
            var nombre = jQuery('#nombre').val();
            var apellido = jQuery('#apellido').val();
            var telefono = jQuery('#telefono').val();
            
            var documentos = [];
            $("input[name='documentos[]']:checked").each(function() {
                documentos.push($(this).val());
            });

            var direccion = jQuery("select[name='direccion']").val();  
            
            $('#Msg').html('<div class="loading"><img src="files/busy.gif" alt="loading" />&nbsp;&nbsp;Procesando, por favor espere...</div>');
            $.ajax({
                url:"update.php",
                type:"POST",
                cache:false,
                data:{valor:valor, nombre:nombre, apellido:apellido, telefono:telefono, documentos:documentos, direccion:direccion},  // Enviando la dirección
                success:function(data){
                    if (data == 1) {
                        jQuery('#nombre').val('');
                        jQuery('#apellido').val('');
                        jQuery('#telefono').val('');
                        $("input[name='documentos[]']").prop('checked', false);
                        $("select[name='direccion']").val('12 Octubre');  
                        $("#Msg").html("<div class='alert alert-success' role='alert'>Registrado.</div> ");
                    } else {
                        jQuery('#nombre').val('');
                        jQuery('#apellido').val('');
                        jQuery('#telefono').val('');
                        $("input[name='documentos[]']").prop('checked', false);
                        $("select[name='direccion']").val('12 Octubre');  
                        $("#Msg").html("<div class='alert alert-danger' role='alert'>Error.</div> ");
                    }
                }
            });
        });
    });

</script>
</body>
</html>
