const kaomojis = [
    { kaomoji: "(╯°□°）╯︵ ┻━┻", meaning: "Angry" },
    { kaomoji: "(^_^)", meaning: "Happy" },
    { kaomoji: "(T_T)", meaning: "Sad" },
    { kaomoji: "(o_O)", meaning: "Confused" },
    { kaomoji: "(¬‿¬)", meaning: "Mischievous" },
    { kaomoji: "(✿◕‿◕)", meaning: "Cute" },
    { kaomoji: "(ʘ‿ʘ)", meaning: "Surprised" },
    { kaomoji: "(ಠ_ಠ)", meaning: "Disapproving" },
    { kaomoji: "(｡♥‿♥｡)", meaning: "In Love" },
    { kaomoji: "(｡◕‿◕｡)", meaning: "Happy & Shy" },
    { kaomoji: "(⁄ ⁄•⁄ω⁄•⁄ ⁄)", meaning: "Flushed" }
];

let score = 0;
let round = 1;

function newRound() {
    let currentKaomoji = kaomojis[Math.floor(Math.random() * kaomojis.length)];
    document.getElementById("kaomoji").textContent = currentKaomoji.kaomoji;
    generateOptions(currentKaomoji.meaning);
    updateScoreboard();
    round++;
    document.getElementById("round").textContent = round;
}

function generateOptions(correctAnswer) {
    let optionsContainer = document.getElementById("options");
    optionsContainer.innerHTML = "";
    let shuffled = kaomojis.map(k => k.meaning).sort(() => 0.5 - Math.random()).slice(0, 3);
    if (!shuffled.includes(correctAnswer)) shuffled[Math.floor(Math.random() * 3)] = correctAnswer;
    shuffled.forEach(option => {
        let button = document.createElement("button");
        button.textContent = option;
        button.onclick = () => checkAnswer(option, correctAnswer);
        optionsContainer.appendChild(button);
    });
}

function checkAnswer(selected, correct) {
    let message = document.getElementById("message");
    if (selected === correct) {
        message.textContent = "Correct! 🎉";
        score += 10;
        animateKaomoji("correct");
    } else {
        message.textContent = "Wrong! 😔";
        animateKaomoji("wrong");
    }
    updateScoreboard();
    setTimeout(newRound, 2000);
}

function animateKaomoji(result) {
    let kaomoji = document.getElementById("kaomoji");
    kaomoji.style.transition = "transform 0.5s ease-in-out";
    if (result === "correct") {
        kaomoji.style.transform = "scale(1.2)";
    } else {
        kaomoji.style.transform = "scale(0.8)";
    }
    setTimeout(() => kaomoji.style.transform = "scale(1)", 500);
}

function updateScoreboard() {
    document.getElementById("score").textContent = score;
    if (score >= 50) {
        document.getElementById("message").textContent = "You are a Kaomoji Master! 🏆";
    }
}

newRound();
