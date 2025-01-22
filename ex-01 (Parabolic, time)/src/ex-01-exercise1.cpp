#include "Parab.hpp"
#include <fstream>

// Main function.
int main(int argc, char *argv[])
{
    Utilities::MPI::MPI_InitFinalize mpi_init(argc, argv);
    // const unsigned int mpi_rank = Utilities::MPI::this_mpi_process(MPI_COMM_WORLD);

    const unsigned int degree = 1;

    const double T = 1.0;
    const double theta = 0.5;

    const std::vector<double> deltat_vector = {0.25, 0.125, 0.0625, 0.03125, 0.015625};
    std::vector<double> errors_L2;

    for (const auto &deltat : deltat_vector)
    {
        Parab problem("../mesh/mesh-square-h0.1.msh", degree, T, 0.015625, theta);

        problem.setup();
        problem.solve();

        errors_L2.push_back(problem.compute_error(VectorTools::L2_norm));
    }

    for(auto error:errors_L2)
        std::cout << error << std::endl;

    // Print the errors and estimate the convergence order.
    // if (mpi_rank == 0)
    // {
    //     std::cout << "==============================================="
    //               << std::endl;

    //     std::ofstream convergence_file("convergence.csv");
    //     convergence_file << "dt,eL2" << std::endl;

    //     for (unsigned int i = 0; i < deltat_vector.size(); ++i)
    //     {
    //         convergence_file << deltat_vector[i] << "," << errors_L2[i] << std::endl;

    //         std::cout << std::scientific << "dt = " << std::setw(4)
    //                   << std::setprecision(2) << deltat_vector[i];

    //         std::cout << std::scientific << " | eL2 = " << errors_L2[i];

    //         // Estimate the convergence order.
    //         if (i > 0)
    //         {
    //             const double p =
    //                 std::log(errors_L2[i] / errors_L2[i - 1]) /
    //                 std::log(deltat_vector[i] / deltat_vector[i - 1]);

    //             std::cout << " (" << std::fixed << std::setprecision(2)
    //                       << std::setw(4) << p << ")";
    //         }
    //         else
    //             std::cout << " (  - )";

    //         std::cout << "\n";
    //     }
    // }

    return 0;
}