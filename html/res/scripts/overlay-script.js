window.onload = init;

function init() {
	async function mainLoop() {
		const scInfo = await getInfo();
		doUpdate(scInfo);
	}

	mainLoop();
	setInterval( () => { mainLoop(); }, 500); //update interval
}

//searches for the main json file
function getInfo() {
	return new Promise(function (resolve) {
		const oReq = new XMLHttpRequest();
		oReq.addEventListener("load", reqListener);
		oReq.open("GET", 'overlay-data.json');
		oReq.send();

		//will trigger when file loads
		function reqListener () {
			resolve(JSON.parse(oReq.responseText))
		}
	})
	//i would gladly have used fetch, but OBS local files wont support that :(
}

// meat of the overlay script, does the updating bit
function doUpdate(scInfo) {
    let p1Name = scInfo['p1Name'];
	let p1Team = scInfo['p1Team'];
	let p1Pron = scInfo['p1Pron'];
	let p1Score = scInfo['p1Score'];
	let p1Color = scInfo['p1Color'];
	let p1Character = scInfo['p1Character'];
	let p1Skin = scInfo['p1Skin'];
	let p1WL = scInfo['p1WL'];
	
	let p2Name = scInfo['p2Name'];
	let p2Team = scInfo['p2Team'];
	let p2Pron = scInfo['p2Pron'];
	let p2Score = scInfo['p2Score'];
	let p2Color = scInfo['p2Color'];
	let p2Character = scInfo['p2Character'];
	let p2Skin = scInfo['p2Skin'];
	let p2WL = scInfo['p2WL'];

	let round = scInfo['round'];
	let bestOf = scInfo['bestOf'];

	let caster1 = scInfo['caster1Name'];
	twitter1 = scInfo['caster1Twitter'];
	twitch1 = scInfo['caster1Twitch'];
	let caster2 = scInfo['caster2Name'];
	twitter2 = scInfo['caster2Twitter'];
	twitch2 = scInfo['caster2Twitch'];

	// do simple text changes

    document.getElementById("p1Name").innerHTML = p1Name;
    document.getElementById("p2Name").innerHTML = p2Name;

    document.getElementById("p1Score").innerHTML = p1Score;
    document.getElementById("p2Score").innerHTML = p2Score;


	// change all instances of player scoreboards' colors
	var p1Scoreboards = document.getElementsByName("p1Scoreboard")
	for (var i = 0; i < p1Scoreboards.length; i++)
	{
		p1Scoreboards[i].style.backgroundImage = "linear-gradient(" + p1Color + ", #00000000)";
	}

	var p2Scoreboards = document.getElementsByName("p2Scoreboard")
	for (var i = 0; i < p2Scoreboards.length; i++)
	{
		p2Scoreboards[i].style.backgroundImage = "linear-gradient(" + p2Color + ", #00000000)";
	}

	
	// var p1Characters = document.getElementsByName("p1Character");
	// for (var i = 0; i < p1Characters.length; i++)
	// {
	// 	p1Characters[i].src = "res/characters/Stock Icons/" + p1Character + "/" + p1Character + " (1).png";
	// }

	// var p2Characters = document.getElementsByName("p2Character");
	// for (var i = 0; i < p2Characters.length; i++)
	// {
	// 	p2Characters[i].src = "res/characters/Stock Icons/" + p2Character + "/" + p2Character + " (1).png";
	// }
}