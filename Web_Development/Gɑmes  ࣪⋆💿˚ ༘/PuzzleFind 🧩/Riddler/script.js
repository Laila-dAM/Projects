document.getElementById("start-button").addEventListener("click", function() {
    document.getElementById("start-screen").classList.add("hidden");
    document.getElementById("game-container").classList.remove("hidden");
    loadPuzzle();
});

const puzzles = [
    { 
        kaomoji: "(ʘ‿ʘ)", 
        ascii: "What has to be broken before you can use it?", 
        choices: ["An egg", "A promise", "A window", "A secret"], 
        answer: "An egg" 
    },
    { 
        kaomoji: "(¬‿¬)", 
        ascii: "What comes once in a minute, twice in a moment, but never in a thousand years?", 
        choices: ["The letter M", "A heartbeat", "A shooting star", "A raindrop"], 
        answer: "The letter M" 
    },
    { 
        kaomoji: "(✿◕‿◕)", 
        ascii: "I speak without a mouth and hear without ears. What am I?", 
        choices: ["An echo", "A dream", "A shadow", "A ghost"], 
        answer: "An echo" 
    },
    { 
        kaomoji: "(⊙_◎)", 
        ascii: "The more you take, the more you leave behind. What am I?", 
        choices: ["Footsteps", "Memories", "Holes", "Time"], 
        answer: "Footsteps" 
    }
];

let currentPuzzle = 0;

function loadPuzzle() {
    if (currentPuzzle < puzzles.length) {
        document.getElementById("kaomoji").textContent = puzzles[currentPuzzle].kaomoji;
        document.getElementById("ascii-art").textContent = puzzles[currentPuzzle].ascii;
        document.getElementById("message").textContent = "";
        
        const choicesDiv = document.getElementById("choices");
        choicesDiv.innerHTML = "";
        
        puzzles[currentPuzzle].choices.forEach(choice => {
            let choiceElement = document.createElement("div");
            choiceElement.classList.add("choice");
            choiceElement.textContent = choice;
            choiceElement.onclick = () => checkAnswer(choice);
            choicesDiv.appendChild(choiceElement);
        });
    } else {
        document.getElementById("game-container").innerHTML = "<h1>🎉 You Escaped! 🎉</h1>";
    }
}

function checkAnswer(selected) {
    const correctSound = document.getElementById("correct-sound");
    const wrongSound = document.getElementById("wrong-sound");
    
    if (selected === puzzles[currentPuzzle].answer) {
        correctSound.play();
        document.getElementById("message").textContent = "✅ Correct!";
        document.getElementById("message").style.color = "#ffcc66";
        currentPuzzle++;
        setTimeout(loadPuzzle, 1000);
    } else {
        wrongSound.play();
        document.getElementById("message").textContent = "❌ Wrong answer. Try again.";
        document.getElementById("message").style.color = "#ff3333";
    }
}
