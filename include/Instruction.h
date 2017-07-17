/**
 *  Instruction class.
 *  An instruction includes code and operand.
 */
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class Instruction
{
    public:
        /**
         *  Instruction constructor.
         */
        Instruction();
        /**
         *  Instruction destructor.
         */
        virtual ~Instruction();

        /**
         *  Gets code.
         *  @return code is an integer
         */
        int getCode();
        /**
         *  Gets operand.
         *  @return operand is an integer
         */
        int getOperand();
        /**
         *  Sets code.
         *  @param code is an integer
         */
        void setCode(int code);
        /**
         *  Sets operand.
         *  @param operand is an integer
         */
        void setOperand(int operand);

    protected:

    private:
        int code;
        int operand;
};

#endif // INSTRUCTION_H
