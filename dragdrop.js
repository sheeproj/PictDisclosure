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

            var allMetaData = EXIF.getAllTags(image);

            var tbody = document.getElementById("tbodyID");
            tbody.innerHTML = '';

            var thead = document.createElement('thead');
            var tr0 = document.createElement('tr');
            var td00 = document.createElement('td');
            td00.innerHTML = 'Tag';
            tbody.appendChild(td00);
            var td01 = document.createElement('td');
            td01.innerHTML = 'Value';
            tbody.appendChild(td01);
            tbody.appendChild(tr0);
            
            for (var m in allMetaData) {
                var tr1 = document.createElement('tr');

                // tag
                var td10 = document.createElement('td');
                td10.innerHTML = m;
                tbody.appendChild(td10);

                // value
                var td11 = document.createElement('td');
                td11.innerHTML = allMetaData[m];
                tbody.appendChild(td11);

                tbody.appendChild(tr1);
            }
        });
    }


    return false;
};
