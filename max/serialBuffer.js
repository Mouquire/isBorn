
inlets = 1;
outlets = 1;

var buffer = []; // Contiendra les messages

function sendData() {
	if(buffer.length > 0) { // Si le buffer contient des infos...
		outlet(0, buffer[0]); // ...renvoies-en une seule...
		buffer.splice(0,1); // ...et supprime la du buffer. 

		if(buffer.length === 0) { // Si le buffer ne contient plus d'infos...
			arguments.callee.task.cancel(); // ...arrête la fonction.
		}
	}
}

dataClock = new Task(sendData, this); // Accroche une horloge à la fonction sendData...
dataClock.interval = 5; // ...et initialize cette horloge à 5ms.

function load(motorIndex, speed) { // Infos sur le mouvement.
	var message = "MAX " + motorIndex + " " + speed + "/"; // Prépare le message pour l'arduino.
	buffer.push(message); // Ajoute le au buffer.

	if(dataClock.running === false) { // Si l'horloge envoyant les données n'est pas lancée...
		dataClock.repeat(); // ...lance la (il y a des infos dans le buffer).
	}
}