#include <iostream>
#include <fstream>
#include <sstream>

class CSVWriter {
    std::stringstream ss;

public:
    CSVWriter() {
    }

    template<typename T>
    CSVWriter& operator<<(const T& data) {
        if (!ss.str().empty() && ss.str().back() != '\n') {
            ss << ",";
        }
        ss << data;
        return *this;
    }

    void newRow() {
        ss << '\n';
    }

    void writePoint(double time, double data) {
        *this << time << data << '\n';
    }

    void writeToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << ss.str();
            file.close();
        } else {
            std::cerr << "Failed to open " << filename << std::endl;
        }
    }
};

int main(int argc, char** argv) {
    CSVWriter xPosData;
    for (int i = 0; i < 30; i++) {
        xPosData.writePoint(i, 4738 - i * 4);
    }
    xPosData.writeToFile("data.csv");

}