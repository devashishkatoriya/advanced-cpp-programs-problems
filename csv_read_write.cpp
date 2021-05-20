#include <iostream>
#include <fstream>
#include <vector>

// Function to check if given string is not empty
bool IsNotEmpty(const std::string& str)
{
    return !str.empty();
}

// Template to find end of a pointer array 
template<typename T, size_t N>
T* end(T (&ra)[N]) 
{
    return ra + N;
}

class CSV
{
    std::string file_name;

public:
    CSV()
    {
        file_name = "stub.csv";
    }
    CSV(const std::string& fname)
    {
        this->file_name = fname;
    }

    std::vector<std::vector<std::string>> read_csv()
    {
        std::fstream csv_file;
    
        std::vector<std::vector<std::string>> file_data;

        // Open the csv file in input mode
        csv_file.open(this->file_name, std::ios::in);

        // If file opening was unsuccessful return error
        if(!csv_file) 
        {
            return file_data;
        }

        char ch;
        std::string temp = "";
        std::vector<std::string> cols;
        while (!csv_file.eof()) 
        {
            // Dont skip the whitespace characters while reading
            csv_file >> std::noskipws >> ch;
            //std::cout << ch;
            
            if (ch == ',')
            {
                cols.push_back(temp);
                temp = "";
            }
            else if (ch == '\n')
            {
                cols.push_back(temp);
                temp = "";
                file_data.push_back(cols);
                cols.clear();
            }
            else
            {
                temp += ch;
            }
        }

        // Close the file
        csv_file.close();

        return file_data;
    }

    bool write_line(const std::vector<std::string>& text, const bool& append)
    {
        std::fstream new_file;

        // Open the file
        if (!append)
        {
            new_file.open(this->file_name, std::ios::out);
        }
        else
        {
            new_file.open(this->file_name, std::ios::app);
        }

        // If file opening was unsuccessful return error
        if(!new_file) 
        {
            return false;
        }

        // Get the number of cols to write
        int len = text.size();

        // Write each column
        for (int i=0; i<len; i++)
        {
            new_file<<text[i];
            if (i != len-1)
            {
                new_file<<",";
            }
        }
        
        // Write end-of-line character
        new_file<<"\n";

        // Close the file
        new_file.close();

        // Return successful execution value
        return true;
    }

    void set_file_name(const std::string& fname)
    {
        this->file_name = fname;
    }
    std::string get_file_name() const
    {
        return file_name;
    }

    void display_file()
    {
        // Variable to store read data from file
        std::vector<std::vector<std::string>> read_data;

        read_data = this->read_csv();

        // Display the file data
        for(int i=0; i<read_data.size(); i++)
        {
            std::cout << std::endl;
            for (int j=0; j<read_data[i].size(); j++)
            {
                std::cout << read_data[i][j] << "\t";
            }
        }
    }
};

int main()
{
    // Create a CSV file object with your file name 
    CSV file("test1.csv");

    // Data to write into file
    const char *vinit[] = {
        "Hello",
        "World",
        " How are you?",
        "I'm fine "
    };
    std::vector<std::string> write_data(vinit, end(vinit));

    // Call write_line function with appropiate file mode
    bool result = file.write_line(write_data, false);
    result = file.write_line(write_data, true);
    result = file.write_line(write_data, true);

    // Function to get CSV file name
    std::cout << file.get_file_name() << std::endl;

    // Display the contents of csv file
    file.display_file();

    return 0;
}