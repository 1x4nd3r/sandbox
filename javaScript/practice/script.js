const color = document.getElementById("color")

function setColor(clr) {
    color.style.backgroundColor = clr
}

function rndColor(){
    const Color = Math.floor(Math.random() * 3)
    console.log(Color)

    if(Color == 0){setColor("red")}
    if(Color == 1){setColor("yellow")}
    if(Color == 2){setColor("green")}
}

//--------------------------------------------------//

const inp1 = document.getElementById("inp1")

function check(){
    const value = inp1.value
    var password = "HelloWorld"

    if(value == password){
        console.log("password correct!")
    }
    else{
        console.log(`${value} was not the password.`);
    }
}

//--------------------------------------------------//

const quotes = [
    "one", "two", "three", "four", "five"
]

const usedIndexes = new Set() // make sure to not repeat RNG without cycling through it fully.
const quoteElement = document.getElementById("quote")

function genQuote(){
    const randQ = Math.floor(Math.random() * quotes.length)
    quoteElement.innerHTML = quotes[randQ]
}

//--------------------//

const subj = [
    "I", "You", "It", "They", "God", "Es Majesty", "A lost sock", "An alien", "My pet rock", "The Council of Elders",
    "A sentient toaster", "A confused time traveler", "A rebellious AI", "The moon", "A disgruntled penguin"
];

const verb = [
    "ate", "populated", "destroyed", "caged", "hugged", "questioned", "painted", "worshipped", "misunderstood", "melted",
    "enchanted", "teleported", "betrayed", "forgave", "laughed at", "whispered to"
];

const owner = [
    "my", "your", "it's", "their", "God's", "Es Majesties", "a wizard's", "a hamster's", "the internet's", "the void's",
    "the dragon's", "a ghost's", "the government's", "a squirrel's", "the universe's"
];

const obj = [
    "cat", "mum", "poo", "hair", "spaceship", "pineapple", "conspiracy theory", "rubber chicken", "cloud", "time machine",
    "sock puppet", "mystical amulet", "sentient pancake", "portal to another dimension", "jellyfish wearing sunglasses"
];

const ending = [
    "... WELL DONE!", "HOW DARE YOU!?", "...", "!", "..?", "Behold, destiny!", "I have concerns.", "Why would you do this?", "This will be remembered.", "Existence is pain.",
    "Reality is broken.", "This changes everything!", "Oh dear.", "Congratulations, I guess?", "Prepare for the consequences."
];



const pSubj = document.getElementById("subj")
const pVerb = document.getElementById("verb")
const pOwner = document.getElementById("owner")
const pObj = document.getElementById("obj")
const pEnding = document.getElementById("ending")


function genQuote2(){
    const genSubj = Math.floor(Math.random() * subj.length)
    const genVerb = Math.floor(Math.random() * verb.length)
    const genOwner = Math.floor(Math.random() * owner.length)
    const genObj = Math.floor(Math.random() * obj.length)
    const genEnding = Math.floor(Math.random() * ending.length)
    
    pSubj.innerHTML = subj[genSubj];
    pVerb.innerHTML = verb[genVerb];
    pOwner.innerHTML = owner[genOwner];
    pObj.innerHTML = obj[genObj];
    pEnding.innerHTML = ending[genEnding];
}