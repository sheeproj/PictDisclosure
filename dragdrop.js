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

    var timestamp = new Date().getTime();

    // show source image
    var image = document.getElementById('image');
    image.src = file.path + "?" + timestamp;

    // show histogram image
    var histoimage = document.getElementById('histoimage');
    histoimage.src = histoimage_filepath + "?" + timestamp;

    // show EXIF data
    image.onload = function() {

        image.exifdata = null;
        EXIF.getData(this, function() {
            console.log(image);
            console.log(image.src);
            var allMetaData = EXIF.getAllTags(image);
            console.log(allMetaData);
            document.getElementById('exiftext').innerHTML = JSON.stringify(allMetaData, null, "\t");
        });
    }


    return false;
};
