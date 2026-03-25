
function rollDice(){
  function random_dice(){
    let n = Math.floor(Math.random() * 6) + 1;
    console.log(n)
    return n;
  }
  
  // Seleziono ciascuna immagine con querySelector
  const dice1 = document.querySelector('.img1');
  const dice2 = document.querySelector('.img2');

  // Cambio il src con il numero casuale
  dice1.src = `images/dice${random_dice()}.png`;
  dice2.src = `images/dice${random_dice()}.png`;
}
window.onload = rollDice;

