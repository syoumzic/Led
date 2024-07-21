#pragma once

#include <SimpleCLI.h>

class CustomCLI{
    private:
        SimpleCLI mCLI;
    public:
        void setup();

        Command addCommand(const char* name, void (* callback)(cmd* c) = NULL);
        static void errorCallback(cmd_error* e);
        void parse(String& input);
        void parse(const char* input);
        void parse(const char* input, size_t input_len);
};

extern CustomCLI CLI;