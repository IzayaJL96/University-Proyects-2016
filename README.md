# University-Proyects-
# Early Embedded Projects — University Period (2016–2017)

Collection of Arduino-based robotics projects developed during my 
Systems Engineering degree at Universidad Cooperativa de Colombia.

These projects represent my first hands-on work with microcontrollers,
actuator control, sensor integration, and autonomous behavior logic.

---

## Projects

### BB-9 Robot Series
Hardware base: repurposed RC car with self-locking differential,
rebuilt from scratch for autonomous operation.

| File | Description |
|------|-------------|
| `BB-9.ino` | Sequential movement control — motor + steering |
| `BB-9_EVASOR.ino` | Obstacle avoidance with 4 ultrasonic sensors + line follower |
| `BB-9_SUMO.ino` | Sumo competition logic — ring detection + enemy targeting |

The physical robot was built by recycling a RC car chassis, 
repurposing its self-locking differential as the drive system.
No off-the-shelf robot kit — hardware designed and assembled 
from available components.

### IZAYA Motor Control Series
Independent dual-motor architecture (vs. motor+steering in BB-9).

| File | Description |
|------|-------------|
| `IZAYA_MOTORES.ino` | Dual independent motor control — directional logic |
| `IZAYA_SUMO.ino` | Sumo variant with ultrasonic + line follower |

> Note: Remote control version (`IZAYA_MOTORES`) was started 
> but not completed — documented here as-is for portfolio continuity.

### Pololu Zumo Platform
Projects using the Pololu Zumo robot with its dedicated libraries.

| File | Description |
|------|-------------|
| `POLOLU_RobotSumo.ino` | Sumo competition with ultrasonic targeting |
| `POLOLU_Seguidor_Linea.ino` | PID-based line follower |

The line follower implements a basic proportional-derivative 
controller — first contact with control systems concepts.

### Semaforo.ino
Traffic light simulation — introductory GPIO and timing exercise.

---

## Technical progression visible in this repo
---

## Context

These projects were developed under a project-based learning 
methodology where each course required a functional hardware 
deliverable. Code quality and documentation standards were 
enforced from the first project.

Fast-forward to 2026: the same hands-on approach now drives 
an open-source wearable telemetry system for motorsport.
→ [moto-telemetry](https://github.com/IzayaJL96/moto-telemetry)

---

## Hardware notes

- **BB-9 base**: repurposed RC car — self-locking differential 
  retained as drive mechanism
- **Platform**: Arduino (various boards)
- **Sensors**: HC-SR04 ultrasonic, QTR reflectance array (Pololu)
- **Period**: 2016–2017
