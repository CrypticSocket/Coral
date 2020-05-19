const burger = document.querySelector('.burger')
const nav = document.querySelector('.linksside')
const stats = document.getElementById('statsHolder')

burger.addEventListener('click', function(){
    nav.classList.toggle('nav-active')
    burger.classList.toggle('burger-active')
})

function readGist()
{
    const request = new XMLHttpRequest();
    var elementBot
    request.open("GET", "https://gist.githubusercontent.com/CrypticSocket/add6f0a7427b7d735b18f111acddbca9/raw/trial.txt", true); 
    request.onreadystatechange = () => {
        if(request.readyState === XMLHttpRequest.DONE) {
            var status = request.status;
            if (status === 0 || (status >= 200 && status < 400)) {
                var data = JSON.parse(request.responseText)
                data.forEach(nodeBot => {
                    elementBot = `<div class="card">
                        <table>
                            <tr>
                                <td>NodeName</td>
                                <td class="right">${nodeBot.NodeName}</td>
                            </tr>
                            <tr>
                                <td>pH</td>
                                <td class="right">${nodeBot.pH}</td>
                            </tr>
                            <tr>
                                <td>Temp</td>
                                <td class="right">${nodeBot.Temperature} &#8451</td>
                            </tr>
                            <tr>
                                <td>Condition</td>
                                <td class="right">${nodeBot.State}</td>
                            </tr>
                        </table>
                    </div>`
                    stats.innerHTML+=elementBot
                })
                // alert(stats.innerHTML)
                console.log("Successful")
            } else {
                console.log("Failed. Check internet connection")
            }
          }
    };
    request.send();
}

readGist();