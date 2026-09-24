const red = document.getElementById("number");
const prikazReda = document.getElementById("matrix-size");
const prikazMatrice = document.getElementById("matrix-display");
const infoText = document.getElementById("info-text");
red.addEventListener("change", function() {
   prikazReda.textContent = red.value + " × " + red.value;
});

const opcije = document.querySelectorAll('input[name="vrsta"]');

const generateBtn = document.getElementById("generate-btn");
generateBtn.addEventListener("click", function() {
    const odabranaOpcija = document.querySelector('input[name="vrsta"]:checked');

    if (odabranaOpcija == null) {
    alert("Odaberite vrstu matrice!");
    return;
    }


   Module.ccall(
    "GenerirajMatricu",
    null,
    ["number", "number"],
    [Number(red.value), Number(odabranaOpcija.value)]
);
prikazMatrice.innerHTML = "";
let htmlMatrice = "";

for (let i = 0; i < Number(red.value); i++) {

    htmlMatrice += '<div class="matrix-row">';

    for (let j = 0; j < Number(red.value); j++) {

        const element = Module.ccall(
            "DohvatiElement",
            "number",
            ["number", "number"],
            [i, j]
        );

        htmlMatrice += "<span>" + element + "</span>";
    }

    htmlMatrice += "</div>";
}

prikazMatrice.innerHTML = htmlMatrice;
if (odabranaOpcija.value == "1") {
    infoText.innerHTML =
    "<p>Generirana je nul-matrica reda " + red.value +
    ".<br>Svi elementi matrice jednaki su 0.</p>";
}
else if (odabranaOpcija.value == "2") {
    infoText.innerHTML =
        "<p>Generirana je dijagonalna matrica reda " + red.value +
        ".<br>Svi elementi izvan glavne dijagonale jednaki su 0.</p>";
}
else if (odabranaOpcija.value == "3") {
    infoText.innerHTML =
        "<p>Generirana je jedinična matrica reda " + red.value +
        ".<br>Na glavnoj dijagonali nalaze se jedinice, a ostali elementi su 0.</p>";
}
else if (odabranaOpcija.value == "4") {
    infoText.innerHTML =
        "<p>Generirana je gornja trokutasta matrica reda " + red.value +
        ".<br>Svi elementi ispod glavne dijagonale jednaki su 0.</p>";
}
else if (odabranaOpcija.value == "5") {
    infoText.innerHTML =
        "<p>Generirana je donja trokutasta matrica reda " + red.value +
        ".<br>Svi elementi iznad glavne dijagonale jednaki su 0.</p>";
}
else if (odabranaOpcija.value == "6") {
    infoText.innerHTML =
        "<p>Generirana je simetrična matrica reda " + red.value +
        ".<br>Vrijedi a[i][j] = a[j][i].</p>";
}
else if (odabranaOpcija.value == "7") {
    infoText.innerHTML =
        "<p>Generirana je antisimetrična matrica reda " + red.value +
        ".<br>Vrijedi a[i][j] = -a[j][i], a elementi glavne dijagonale su 0.</p>";
}
});

const resetBtn = document.getElementById("reset-btn");

resetBtn.addEventListener("click", function() {
    opcije.forEach(function(opcija) {
        opcija.checked = false;
    });

    red.value = "1";
    prikazReda.textContent = "1 × 1";
    prikazMatrice.innerHTML = "";
    infoText.innerHTML = "";
});