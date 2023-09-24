
#include "../include/SAV.hh"

#include <iostream>

int main() {
    // Inisialisasi SFML
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Audio");
    sf::Music music;

    // Muat file audio (misalnya, lagu MP3)
    if (!music.openFromFile("../sample.ogg")) {
        std::cerr << "Failed to load audio file" << std::endl;
        return 1;
    }

    // Putar audio
    music.play();

    // Loop utama
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Tambahan: Hentikan audio jika tombol Escape ditekan
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            music.stop();
        }

        window.clear();
        window.display();
    }

    return 0;
}
