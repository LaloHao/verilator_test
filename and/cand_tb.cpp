#include "Vcand.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env)
{
  int clk;
  Verilated::commandArgs(argc, argv);
  Vcand *top = new Vcand;
  Verilated::traceEverOn(true);
  VerilatedVcdC *tfp = new VerilatedVcdC;
  top->trace(tfp, 99);
  tfp->open("cand.vcd");
  top->a = 0;
  top->b = 0;
  for(clk = 0; clk <= 4; clk++)
    {
      tfp->dump(clk);
      top->a = !top->a;
      top->b = (clk >= 1);
      top->eval();
    }
  if(Verilated::gotFinish())
    exit(0);
  tfp->close();
  exit(0);

  return 0;
}
