#ifndef SNRTHRESHOLDDECIDEROLD_H_
#define SNRTHRESHOLDDECIDEROLD_H_

#include <BaseDecider.h>

/**
 * @brief BaseDecider implementation which decides a signals
 * correctness by checking its SNR against a threshold.
 *
 * @ingroup decider
 */
class SNRThresholdDeciderOld : public BaseDecider
{
protected:
	/** @brief Threshold value for checking a SNR-map (SNR-threshold).*/
	double snrThreshold;

protected:

	/**
	 * @brief Checks a mapping against a specific threshold (element-wise).
	 *
	 * @return	true	, if every entry of the mapping is above threshold
	 * 			false	, otherwise
	 *
	 *
	 */
	virtual bool checkIfAboveThreshold(Mapping* map, simtime_t start, simtime_t end);


	/**
	 * @brief Processes a received AirFrame.
	 *
	 * The SNR-mapping for the Signal is created and checked against the Deciders
	 * SNR-threshold. Depending on that the received AirFrame is either sent up
	 * to the MAC-Layer or dropped.
	 *
	 * @return	usually return a value for: 'do not pass it again'
	 */
	virtual simtime_t processSignalEnd(AirFrame* frame);

public:

	/**
	 * @brief Initializes the Decider with a pointer to its PhyLayer and
	 * specific values for threshold and sensitivity
	 */
	SNRThresholdDeciderOld(DeciderToPhyInterface* phy,
				double threshold,
				double sensitivity,
				int myIndex = -1,
				bool debug = false):
		BaseDecider(phy, sensitivity, myIndex, debug),
		snrThreshold(threshold)
	{}

	virtual ~SNRThresholdDeciderOld() {};
};

#endif /* SNRTHRESHOLDDECIDEROLD_H_ */
