
let nom = "Farissi";
let prenom = "Abderrahmane";

const Combine = (n, p) => `${n}, ${p}`;

let NomComplet = Combine(nom, prenom);

if (NomComplet.length > 15) {
    console.log("Nom long");
} else {
    console.log("Nom petite");
}