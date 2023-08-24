let empleados = [];

function mostrarResultado(resultado) {
  document.getElementById("resultados").innerHTML = resultado;
}

function calcularEdadesYBonificaciones() {
  // Obtener datos del formulario
  const nombre = document.getElementById("nombre").value;
  const cedula = document.getElementById("cedula").value;
  const fechaNacimiento = document.getElementById("fechaNacimiento").value;
  const sueldo = parseFloat(document.getElementById("sueldo").value);
  const cargasFamiliares = parseInt(document.getElementById("cargasFamiliares").value);

  // Lógica para calcular la edad
  const fechaActual = new Date();
  const fechaNacimientoDate = new Date(fechaNacimiento);
  const diff = fechaActual - fechaNacimientoDate;
  const edad = Math.floor(diff / (1000 * 60 * 60 * 24 * 365));

  // Lógica para calcular la bonificación
  const bonificacion = sueldo * (0.05 * cargasFamiliares);

  // Mostrar los resultados en el área de resultados
  const resultadoHTML = `
    <h2>Resultados:</h2>
    <div>
      <p>Nombre: ${nombre}</p>
      <p>Cédula: ${cedula}</p>
      <p>Edad: ${edad} años</p>
      <p>Bonificación: $${bonificacion.toFixed(2)}</p>
    </div>
  `;
  empleados.push({
    nombre: nombre,
    cedula: cedula,
    edad: edad,
    bonificacion: bonificacion
  });
  mostrarResultado(resultadoHTML);
}

function buscarEmpleado() {
  const cedulaBuscada = document.getElementById("cedula").value;
  const empleadoEncontrado = empleados.find((empleado) => empleado.cedula === cedulaBuscada);

  if (empleadoEncontrado) {
    // Mostrar los datos del empleado en el área de resultados
    const resultadoHTML = `
      <h2>Resultados:</h2>
      <div>
        <p>Nombre: ${empleadoEncontrado.nombre}</p>
        <p>Cédula: ${empleadoEncontrado.cedula}</p>
        <p>Edad: ${empleadoEncontrado.edad} años</p>
        <p>Bonificación: $${empleadoEncontrado.bonificacion.toFixed(2)}</p>
      </div>
    `;
    mostrarResultado(resultadoHTML);
  } else {
    mostrarResultado("Empleado no encontrado.");
  }
}
