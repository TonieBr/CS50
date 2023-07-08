       // Way for function to execute only when HTML has loaded!
        document.addEventListener('DOMContentLoaded', function() {
        document.querySelector('form').addEventListener('submit', function(event){
        let name = document.querySelector('#name').value;
        alert('hello, ' + name);
        event.preventDefault();
    });
});