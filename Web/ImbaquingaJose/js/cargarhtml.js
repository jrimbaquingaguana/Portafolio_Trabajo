// JavaScript Document
function cargarPagina(url) {
    var contenidoDiv2 = document.getElementById('contenido');
    var objectTag = document.createElement('object');
    objectTag.setAttribute('data', url);
    contenidoDiv2.innerHTML = ''; // Limpiamos el contenido anterior
    contenidoDiv2.appendChild(objectTag);
}
