#ifndef PID_H
#define PID_H

class PID {
public:

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
   * PID intermediate variables
   */
  bool is_initialized;
  bool is_first_pid_loop;
  double cte_prev;
  double cte_int;
  double tau;

  double steering;
  double max_steering;
  double min_steering;
  /*
  * Constructor
  */
  PID();
  /*
  * Destructor.
  */
  virtual ~PID();
  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);
  /*
  * Compute PID steering given crosstrack error
  */
  double ComputeSteering(double cte);

};

#endif /* PID_H */
