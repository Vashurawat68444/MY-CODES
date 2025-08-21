let user_score = 0;
let comp_score = 0;
let msg = document.querySelector("#msg");
let msgcontainer = document.querySelector(".msg-container");
let userPara = document.querySelector("#user-score");
let compPara = document.querySelector("#comp-score");

const choices = document.querySelectorAll(".choice");

const genComp_choice = () => {
    const options = ["Rock", "Paper", "Scissors"]
    let randIdx = Math.floor(Math.random()*3)
    return options[randIdx];
}

const show_Win = (userWin, userChoice, compChoice) => {
    if(userWin){
        userPara.innerText = ++user_score;
        msg.innerText = `You Win : Your ${userChoice} beats ${compChoice}`;
        msg.style.backgroundColor = "green";
    }
    else if(userWin != true){
        compPara.innerText = ++comp_score;
        msg.innerText = `You Win : Your ${userChoice} lost by ${compChoice}`;
        msg.style.backgroundColor = "red";
    }
}

const playgame = (choiceId) => {
    let user_choice = choiceId
    let comp_choice = genComp_choice();

    if(user_choice === comp_choice){
        console.log("Draw");
        msg.innerText = "Draw";
        msg.style.backgroundColor = "#081b31";
    }else{
        let userWin = true;
        if(user_choice === "Rock")
            userWin = comp_choice === "Paper"? false : true;
        else if(user_choice === "Paper")
            userWin = comp_choice === "Scissors"? false : true;
        else if(user_choice === "Scissors")
            userWin = comp_choice === "Rock"? false : true;
        
        show_Win(userWin, user_choice, comp_choice);
    }
}
choices.forEach((choice) => {
    choice.addEventListener("click", () => {
        let choiceId = choice.getAttribute("id");
        playgame(choiceId);
    })    
});