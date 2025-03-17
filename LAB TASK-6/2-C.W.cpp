#include <iostream>
#include <string>
using namespace std;

class MediaFile {
protected:
    string filePath;
    double size;

public:
    MediaFile(string filePath, double size)
        : filePath(filePath), size(size) {}

    virtual ~MediaFile() {}

    virtual void play() {
        cout << "Playing media file: " << filePath << endl;
    }

    virtual void stop() {
        cout << "Stopping media file: " << filePath << endl;
    }

    virtual void displayDetails() const {
        cout << "File path: " << filePath << ", Size: " << size << " MB" << endl;
    }
};

class VisualMedia : virtual public MediaFile {
protected:
    int resolutionWidth;
    int resolutionHeight;

public:
    VisualMedia(string filePath, double size, int resolutionWidth, int resolutionHeight)
        : MediaFile(filePath, size), resolutionWidth(resolutionWidth), resolutionHeight(resolutionHeight) {}

    void displayDetails() const override {
        MediaFile::displayDetails();
        cout << "Resolution: " << resolutionWidth << "x" << resolutionHeight << endl;
    }
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;

public:
    AudioMedia(string filePath, double size, int sampleRate)
        : MediaFile(filePath, size), sampleRate(sampleRate) {}

    void displayDetails() const override {
        MediaFile::displayDetails();
        cout << "Sample rate: " << sampleRate << " Hz" << endl;
    }
};

class VideoFile : public AudioMedia, public VisualMedia {
public:
    VideoFile(string filePath, double size, int resolutionWidth, int resolutionHeight, int sampleRate)
        : MediaFile(filePath, size), AudioMedia(filePath, size, sampleRate), VisualMedia(filePath, size, resolutionWidth, resolutionHeight) {}

    void play() override {
        cout << "Playing video file: " << filePath << endl;
    }

    void stop() override {
        cout << "Stopping video file: " << filePath << endl;
    }

    void displayDetails() const override {
        MediaFile::displayDetails();
        cout << "Resolution: " << resolutionWidth << "x" << resolutionHeight << endl;
        cout << "Sample rate: " << sampleRate << " Hz" << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string filePath, double size, int resolutionWidth, int resolutionHeight)
        : VisualMedia(filePath, size, resolutionWidth, resolutionHeight) {}

    void displayDetails() const override {
        MediaFile::displayDetails();
        cout << "Resolution: " << resolutionWidth << "x" << resolutionHeight << endl;
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string filePath, double size, int sampleRate)
        : AudioMedia(filePath, size, sampleRate) {}

    void displayDetails() const override {
        MediaFile::displayDetails();
        cout << "Sample rate: " << sampleRate << " Hz" << endl;
    }
};



int main() {
    MediaFile* mediaFiles[5];

    mediaFiles[0] = new VideoFile("movie.mp4", 700, 1920, 1080, 48000);
    mediaFiles[1] = new AudioFile("song.mp3", 5, 44100);
    mediaFiles[2] = new ImageFile("photo.jpg", 2, 1920, 1080);
    mediaFiles[3] = new VideoFile("music_video.mp4", 300, 1280, 720, 44100);
    mediaFiles[4] = new AudioFile("podcast.mp3", 50, 22050);

    for (int i = 0; i < 5; ++i) {
        mediaFiles[i]->displayDetails();
        mediaFiles[i]->play();
        mediaFiles[i]->stop();
        cout << "---------------------------------" << endl;
    }

    for (int i = 0; i < 5; ++i) {
        delete mediaFiles[i];
    }
    return 0;
}

