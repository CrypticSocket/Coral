const burger = document.querySelector('.burger')
const nav = document.querySelector('.linksside')

burger.addEventListener('click', function(){
    nav.classList.toggle('nav-active')
    burger.classList.toggle('burger-active')
})