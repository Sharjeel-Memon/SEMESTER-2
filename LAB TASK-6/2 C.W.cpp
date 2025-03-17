#include <iostream>
#include <string>
using namespace std;

// Base class MediaFile
class MediaFile {
protected:
    string filePath;
    double size;
public:
    MediaFile(string path, double s) : filePath(path), size(s) {}
    virtual ~MediaFile() {}
    virtual void play() const { cout << "Playing media file: " << filePath << endl; }
    virtual void stop() const { cout << "Stopping media file: " << filePath << endl; }
};

// class for visual media
class VisualMedia : virtual public MediaFile {
protected:
    int resolutionX, resolutionY;
public:
    VisualMedia(string path, double s, int resX, int resY)
        : MediaFile(path, s), resolutionX(resX), resolutionY(resY) {}
};

// class for audio media
class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string path, double s, int rate)
        : MediaFile(path, s), sampleRate(rate) {}
};

// Derived class VideoFile inheriting from both VisualMedia and AudioMedia
class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double s, int resX, int resY, int rate)
        : MediaFile(path, s), VisualMedia(path, s, resX, resY), AudioMedia(path, s, rate) {}
    void play() const override { cout << "Playing video file: " << filePath << " at " << resolutionX << "x" << resolutionY << " with " << sampleRate << " Hz audio." << endl; }
};

// Derived class ImageFile inheriting from VisualMedia
class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double s, int resX, int resY)
        : MediaFile(path, s), VisualMedia(path, s, resX, resY) {}
    void play() const override { cout << "Displaying image file: " << filePath << " at " << resolutionX << "x" << resolutionY << endl; }
};

// Derived class AudioFile inheriting from AudioMedia
class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double s, int rate)
        : MediaFile(path, s), AudioMedia(path, s, rate) {}
    void play() const override { cout << "Playing audio file: " << filePath << " at " << sampleRate << " Hz" << endl; }
};

int main() {
    MediaFile* mediaFiles[3];
    mediaFiles[0] = new VideoFile("video.mp4", 150.5, 1920, 1080, 44100);
    mediaFiles[1] = new ImageFile("image.jpg", 5.2, 1024, 768);
    mediaFiles[2] = new AudioFile("song.mp3", 3.8, 48000);
    
    for (int i = 0; i < 3; ++i) {
        mediaFiles[i]->play();
        mediaFiles[i]->stop();
    }
    
    for (int i = 0; i < 3; ++i) {
        delete mediaFiles[i];
    }
    
    return 0;
}