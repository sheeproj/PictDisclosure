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

    var addon = require('./build/Release/addon');
    var histoimage_filepath = './histo.bmp';
    console.log(addon.Histogram(file.path, histoimage_filepath));

    // show source image
    var image = document.getElementById('image');
    image.src = file.path;

    // show histogram image
    var histoimage = document.getElementById('histoimage');
    var timestamp = new Date().getTime();
    histoimage.src = histoimage_filepath + "?" + timestamp;

    return false;
};
