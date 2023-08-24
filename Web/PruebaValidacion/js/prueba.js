function validar() {
    var numero = parseFloat(document.getElementById('numero').value);

    if (isNaN(numero)) {
        alert("Por favor, ingresa un numero valido.");
        return false;
    }

    if (numero <= 0 || numero % 2 === 0) {
        alert("Por favor, ingresa un numero impar, entero y positivo.");
        return false;
    } else {
        alert("Se ingreso el dato correctamente");
        return true;
    }
}

function separar() {
    var numero = parseInt(document.getElementById('numero').value);

    if (isNaN(numero)) {
        alert("Por favor, ingresa un numero valido.");
        return;
    }

    var unidades = numero % 10;
    var decenas = Math.floor((numero % 100) / 10);
    var centenas = Math.floor((numero % 1000) / 100);
    var unidadesDeMil = Math.floor((numero % 10000) / 1000);
    var decenasDeMil = Math.floor((numero % 100000) / 10000);
    var centenasDeMil = Math.floor(numero / 100000);



    var resultadoDiv = document.getElementById('resultado');
    resultadoDiv.innerHTML =
        "Numero ingresado: " + numero + "<br>" +
        "Centenas de Mil: " + centenasDeMil + "<br>" +
        "Decenas de Mil: " + decenasDeMil + "<br>" +
        "Unidades de Mil: " + unidadesDeMil + "<br>" +
        "Centenas: " + centenas + "<br>" +
        "Decenas: " + decenas + "<br>" +
        "Unidades: " + unidades;
}
function sumaEntreNumeros() {
    var numero = document.getElementById('numero').value;

    // Expresión regular para verificar números enteros o flotantes positivos
    var numeroPattern = /^[+]?\d+(\.\d+)?$/;

    if (!numeroPattern.test(numero)) {
        alert("Por favor, ingresa un numero valido positivo (entero o flotante).");
        return false;
    }

    numero = parseFloat(numero);
    
    var numeroCadena = numero.toString();
    var numeroReverso = numeroCadena.split('').reverse().join('');
    
    var decimalPart = numero - Math.floor(numero);

    var sumaTotal = 0;

    for (var i = 0; i < numeroCadena.length; i++) {
        if (!isNaN(parseInt(numeroCadena[i]))) {
            sumaTotal += parseInt(numeroCadena[i]);
        }
    }

    var resultadoDiv = document.getElementById('resultado');
    resultadoDiv.innerHTML = 
        "Numero original: " + numeroCadena + "<br>" +
        "Numero al reves: " + numeroReverso + "<br>" +
        "Suma de unidades: " + sumaTotal + "<br>" +
        "Parte decimal: " + decimalPart.toFixed(2);
    
    return false;
}
function analizarTexto() {
    var texto = document.getElementById('texto').value;

    // Longitud del texto
    var longitud = texto.length;

    // Texto original
    var textoOriginal = texto;

    // Texto invertido por palabra
    var palabras = texto.split(' ');
    var palabrasReverso = palabras.map(function(palabra) {
        return palabra.split('').reverse().join('');
    });
    var textoReverso = palabrasReverso.join(' ');

    var resultadoDiv = document.getElementById('resultado');
    resultadoDiv.innerHTML =
        "Longitud del texto tiene : " + longitud + " caracteres<br>" +
        "Texto original: " + textoOriginal + "<br>" +
        "Texto al reves por palabra: " + textoReverso;

    return false;
}