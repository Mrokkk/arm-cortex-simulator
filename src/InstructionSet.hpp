#pragma once

#include <vector>
#include <string>
#include <stdint.h>
#include <functional>

using Opcode = uint16_t;

class Instruction {

    std::string name_;
    Opcode mask_;
    Opcode code_;

public:

    Instruction(const std::string &name, Opcode mask, Opcode code)
            : name_(name), mask_(mask), code_(code) {
    }

    const std::string name() const {
        return name_;
    }

    bool operator==(Opcode opcode) const {
        return (((opcode >> 8) & mask_) ^ code_) == 0;
    }

};

class ThumbInstructionSet {

    std::vector<Instruction> list_ = {
        {"lsl", 0b11111000, 0b00000000},
        {"lsr", 0b11111000, 0b00001000},
        {"asr", 0b11111000, 0b00010000},
        {"add", 0b11111010, 0b00011000},
        {"sub", 0b11111010, 0b00011010},
    };

public:
    Instruction &get(Opcode opcode) {
        for (auto &inst : list_) {
            if (inst == opcode) {
                return inst;
            }
        }
        throw std::runtime_error("No such Instruction");
    }

};

