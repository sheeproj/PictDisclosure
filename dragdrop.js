document.ondragover = document.ondrop = function(e) {
    e.preventDefault();
    return false;
};

var holder = document.getElementById('holder');
holder.ondragover = function () {
    return false;
};
holder.ondragleave = holder.ondragend = function () {
    return false;
};
holder.ondrop = function (e) {
    e.preventDefault();

    var file = e.dataTransfer.files[0];

    var title = document.getElementById('title');

    title.innerText = 'PictDisclosure : ' + file.name;
    console.log(file.path);

    var image = document.getElementById('image');
    image.src = file.path;

    var myExtension = require('./cpp/build/Release/addon');
    console.log(myExtension.hello()); // hello, world が出力される

    return false;
};
