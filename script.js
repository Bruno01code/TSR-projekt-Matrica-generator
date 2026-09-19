const red = document.getElementById("number");
const prikazReda = document.getElementById("matrix-size");
red.addEventListener("change", function() {
   prikazReda.textContent = red.value + " × " + red.value;
});

const opcije = document.querySelectorAll('input[name="vrsta"]');
opcije.forEach(function(opcija) {
    opcija.addEventListener("change", function() {
        console.log(opcija.value);
    });
});

const generateBtn = document.getElementById("generate-btn");
generateBtn.addEventListener("click", function() {
    const odabranaOpcija = document.querySelector('input[name="vrsta"]:checked');

    if (odabranaOpcija == null) {
    alert("Odaberite vrstu matrice!");
    return;
}

   console.log("Red:", red.value);
   console.log("Vrsta:", odabranaOpcija.value);
});

const resetBtn = document.getElementById("reset-btn");

resetBtn.addEventListener("click", function() {
    opcije.forEach(function(opcija) {
        opcija.checked = false;
    });
      red.value = "1";
    prikazReda.textContent = "1 × 1";
});