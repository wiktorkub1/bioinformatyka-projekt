#include <iostream>
#include <map>
#include <random>
#include <vector>

enum class SpectrumErrors { NEGATIVE_ERRORS = 0, POSITIVE_ERRORS = 1 };

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Too few arguments" << std::endl;
    }

    int DNA_length = int(*argv[1]) - 48;
    int ONT_length = int(*argv[2]) - 48;
    // spectrum spectrum = argv[3] // TO-DO: Add spectrum
    std::string startingONT = argv[4];
    SpectrumErrors spectrumErrors;
    if ((int(*argv[3]) - 48) == 1) {
        spectrumErrors = SpectrumErrors::POSITIVE_ERRORS;
    } else {
        spectrumErrors = SpectrumErrors::NEGATIVE_ERRORS;
    }

    std::cout << "DNA_length: " << DNA_length << std::endl;
    std::cout << "ONT_length: " << ONT_length << std::endl;
    std::cout << "Spectrum: " << std::endl;  // TO-DO: Add spectrum
    if (spectrumErrors == SpectrumErrors::POSITIVE_ERRORS) {
        std::cout << "spectrumErrors: POSITIVE" << std::endl;
    } else {
        std::cout << "spectrumErrors: NEGATIVE" << std::endl;
    }
    std::cout << "startingONT: " << startingONT << std::endl;

    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_int_distribution<int> distribution(0, 3);

    std::map<int, char> alphabet{{0, 'A'}, {1, 'T'}, {2, 'C'}, {3, 'G'}};

    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;

    std::vector<char> sequence;
    sequence.reserve(DNA_length);

    for (int i = 0; i < DNA_length; ++i) {
        sequence.push_back(alphabet[distribution(random_engine)]);
    }

    for (auto& single_char : sequence) {
        std::cout << single_char;
    }
    std::cout << std::endl;
}