

#pragma once


// Forward Declarations
namespace prnn { class RecurrentOpsHandle; }

namespace prnn { namespace matrix { class DynamicView;      } }
namespace prnn { namespace matrix { class ConstDynamicView; } }
namespace prnn { namespace matrix { class Precision;        } }
namespace prnn { namespace matrix { class Matrix;           } }


namespace prnn
{
namespace rnn
{

size_t getMaximumSizeRNNForThisGPU(const matrix::Precision&);

void forwardPropRecurrent(
    const matrix::DynamicView& activations,
    const matrix::ConstDynamicView& weights,
    const matrix::DynamicView& scratch,
    const matrix::DynamicView& reserve,
    const RecurrentOpsHandle& handle);

void backPropDeltasRecurrent(const matrix::DynamicView& deltas,
    const matrix::ConstDynamicView& weights,
    const matrix::ConstDynamicView& activations,
    const matrix::DynamicView& scratch,
    const matrix::ConstDynamicView& reserve,
    const RecurrentOpsHandle& handle);

void backPropGradientsRecurrent(const matrix::DynamicView& dWeights,
    const matrix::ConstDynamicView& activations,
    const matrix::ConstDynamicView& deltas,
    const matrix::ConstDynamicView& scratch,
    const matrix::ConstDynamicView& reserve,
    const RecurrentOpsHandle& handle);

size_t getForwardPropScratchSize(const RecurrentOpsHandle& handle,
    const matrix::Precision& precision);
size_t getBackPropDeltasScratchSize(const RecurrentOpsHandle& handle,
    const matrix::Precision& precision);
size_t getBackPropGradientsScratchSize(const RecurrentOpsHandle& handle,
    const matrix::Precision& precision);

matrix::Matrix getForwardPropScratch(const RecurrentOpsHandle& handle,
    const matrix::Precision& precision);
matrix::Matrix getBackPropDeltasScratch(const RecurrentOpsHandle& handle,
    const matrix::Precision& precision);
matrix::Matrix getBackPropGradientsScratch(const RecurrentOpsHandle& handle,
    const matrix::Precision& precision);


}
}


