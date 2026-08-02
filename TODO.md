# Training evolution roadmap

This document records the conclusions and proposed actions for evolving the
*C++ Software Engineering* training. The aim is to make it complementary to
*Scientific C++*, *Trustworthy Numerical Computing*, and the separate version
control training.

It is a planning document. Checked items should represent completed work that
has been reflected consistently in the course description, slides, examples,
exercises, and setup instructions.


## Agreed course boundary

The three technical trainings should answer different questions:

| Training | Primary question |
|---|---|
| Scientific C++ | How are scientific computations expressed correctly and idiomatically in C++? |
| Trustworthy Numerical Computing | What evidence shows that a numerical result is scientifically trustworthy? |
| C++ Software Engineering | How is C++ software structured, built, tested, analysed, documented, and deployed so that it remains maintainable? |

The version control training remains responsible for version control concepts
and workflows. If it also covers continuous integration, this course should
reference that material rather than repeat it.

Consequences for this course:

- Assume that participants know C++ syntax, classes, inheritance, templates,
  smart pointers, STL algorithms, ranges, exceptions, and basic CMake usage.
- Do not reteach floating-point arithmetic, numerical tolerances,
  conditioning, stability, convergence, validation, or numerical
  reproducibility. These belong to *Trustworthy Numerical Computing*.
- It is acceptable to encode a supplied numerical requirement in Catch2, but
  this course should not derive or justify that requirement.
- Concentrate on architecture, testability, build and dependency management,
  quality automation, documentation, and deployment.
- Distinguish language mechanisms from engineering decisions. *Scientific
  C++* explains how virtual dispatch, CRTP, concepts, variants, and type
  erasure work; this course explains when each is appropriate at an
  architectural boundary.


## Modular delivery model

Offer a complete conceptual core and two optional practical modules. Optional
modules practise the core concepts; they must not introduce prerequisites for
later mandatory material.

| Offering | Duration | Intended outcome |
|---|---:|---|
| Core seminar | 4 hours | Understand and evaluate software-engineering practices |
| Core plus one laboratory | 6 hours | Apply a selected part of the workflow |
| Core plus both laboratories | 8 hours | Integrate tooling, testing, and design in a prepared application |


### Core seminar: 4 hours

The core may contain short instructor demonstrations, but it should not depend
on participants completing exercises during the session.

| Subject | Duration |
|---|---:|
| Scope and relationship to companion courses | 10 min |
| Production-oriented CMake and dependency management | 40 min |
| Compiler warnings, static analysis, and sanitizers | 35 min |
| Test architecture with Catch2 and CTest | 40 min |
| Break | 10 min |
| Modular architecture and SOLID | 35 min |
| Patterns for scientific C++ | 45 min |
| CI, documentation, and adoption strategy | 15 min |
| Wrap-up | 10 min |


### Optional laboratory A: engineering tooling, 2 hours

Use a supplied repository with controlled defects and a documented
environment. Participants should:

1. configure and build the project;
2. run its tests;
3. enable warnings and sanitizers;
4. investigate static-analysis findings;
5. add or improve a test;
6. register it with CTest;
7. run the complete quality workflow.

Provide a stable starter, reference solution, exact commands, expected
results, progressive hints, and automated checkpoints. The same material must
work as a trainer-led or self-paced laboratory.


### Optional laboratory B: architecture and refactoring, 2 hours

All participants should work on the same prepared scientific application.
They should:

1. characterize existing behaviour with tests;
2. separate the computational kernel from I/O and configuration;
3. introduce a testable dependency boundary;
4. add an Adapter or Facade around an external concern;
5. inject an algorithm, policy, or backend;
6. add diagnostics without coupling them to the kernel;
7. verify the refactoring with tests and quality tools;
8. update the relevant documentation and build configuration.


### No official bring-your-own-project track

Do not advertise a bring-your-own-project option as part of the standard
course. It does not scale with one trainer and makes preparation, timing, and
learning outcomes unpredictable.

A general post-course checklist may help participants apply the lessons to
their own software independently. Any project-specific consultation must be a
separate, pre-arranged activity with repository access, build instructions,
dependency information, a narrowly defined question, advance trainer review,
and an explicit project or participant limit.


## Curriculum changes


### Remove or reduce duplicated material

- Remove the standalone functional-programming and ranges section. It belongs
  to *Scientific C++*.
- Remove generic instruction on exception syntax and `std::expected`. Retain
  only engineering concerns such as error-policy boundaries, exception safety,
  and failure reporting.
- Replace basic CMake configure/build instruction with a brief recap or a
  prerequisite reference.
- Do not reteach smart-pointer mechanics. Apply RAII to non-memory scientific
  resources instead.
- Do not teach numerical tolerance selection, convergence testing, scientific
  validation, or cross-platform numerical reproducibility.
- Reduce behaviour-driven-development syntax in favour of test architecture,
  test isolation, component tests, and regression tests.


### Expand software-engineering material

- Target-based CMake design and reusable libraries.
- Public and private build-interface requirements.
- Build and test presets.
- Installation, export, and packaging.
- Reproducible dependency selection and package-manager integration.
- Compiler warnings, clang-tidy/cppcheck, AddressSanitizer, and
  UndefinedBehaviorSanitizer.
- Unit, component, integration, and application-test boundaries.
- Dependency injection and test doubles.
- Automated local quality workflows and CI integration.
- API, contract, ownership, and architectural documentation.
- Configuration, diagnostics, logging, and checkpoint boundaries.


## Design-pattern scope

Patterns should be introduced in response to changing requirements, not as a
catalogue to memorize. Prefer the simplest design that accommodates the actual
variation.


### Core patterns and techniques

- **Strategy:** interchangeable algorithms, initialization methods, boundary
  policies, or stopping conditions.
- **Dependency injection:** provide selected behaviour to the computational
  kernel and replace it during testing.
- **Factory:** construct configured strategies and adapters at the application
  composition boundary.
- **Adapter and Facade:** isolate BLAS/LAPACK, HDF5, FFT, MPI, GPU, file-format,
  configuration, or command-line APIs.
- **Decorator and Observer:** add timing, logging, progress, statistics,
  validation hooks, or checkpointing without modifying the kernel.
- **Pipeline/composition:** represent scientific workflows as independently
  testable stages.
- **RAII resource wrappers:** manage files, MPI objects, HDF5 identifiers, FFT
  plans, GPU resources, and temporary workspaces.


### Compare but do not reteach

- Runtime polymorphism through virtual interfaces.
- `std::variant` and `std::visit` for a small closed set of alternatives.
- Concepts and template policies for compile-time selection.
- CRTP for static polymorphism where it is justified.
- Type erasure for open, value-like runtime polymorphism.

The mechanics of these facilities belong to *Scientific C++*. This course
should compare their coupling, extensibility, ownership, build-time, and
runtime trade-offs.


### Optional or lower-priority material

- **Builder:** retain as optional material unless the example has sufficiently
  complex, validated construction requirements.
- **PIMPL:** retain as optional material for library authors concerned with ABI
  stability, encapsulation, or compile-time isolation.
- **State:** use only where an explicit application lifecycle justifies it. In
  a cellular-automaton example, the term may be confused with the domain state.


## Source-code ownership across repositories

Prefer one authoritative implementation and cross-course links over maintained
copies.

| Material | Intended owner | Proposed action |
|---|---|---|
| Basic CMake and separate compilation | Scientific C++ | Keep there; use as prerequisite material |
| Advanced CMake, testing, installation, and packaging | C++ Software Engineering | Keep and expand here |
| Functional programming and ranges | Scientific C++ | Remove from this course's schedule and link when needed |
| Exception and `std::expected` mechanics | Scientific C++ | Keep there; retain only distinct engineering examples here |
| Builder, Factory, and Strategy examples | C++ Software Engineering | Select the best versions and consolidate here |
| Cellular Automata design example | C++ Software Engineering | Move or migrate here as the running example |
| CRTP and quadrature polymorphism comparisons | Scientific C++ | Keep there and reference them |
| Shapes/type-erasure comparison | Scientific C++ | Keep there and reference it |
| PIMPL | Scientific C++ | Keep as an optional C++ idiom; link if needed |
| Conan, vcpkg, and CPM examples | C++ Software Engineering | Consolidate here and replace duplicates with links |
| Testing and static-analysis examples | C++ Software Engineering | Keep here |
| Numerical validity and reproducibility examples | Trustworthy Numerical Computing | Keep separate; consume supplied requirements only |

Moving material between repositories should be preceded by a comparison of
the existing versions. Preserve the best implementation and useful history;
do not mechanically delete one copy before resolving differences and incoming
links.


## Running example: cellular-automaton experiment application

Use a one-dimensional cellular automaton as the main running example. It has a
small, visual, deterministic core and does not require numerical-analysis
background.

Frame it as an experiment application rather than only an update algorithm:

```text
read experiment configuration
-> initialize a system
-> run the simulation
-> observe selected quantities
-> stop according to a policy
-> write results and metadata
```


### Proof-of-concept starting point

Create a credible research prototype rather than a caricature of bad code:

- approximately 150 to 200 lines in one `main.cpp`;
- `std::vector` for cell storage;
- one elementary cellular-automaton rule;
- periodic boundaries;
- fixed or command-line-supplied cell and generation counts;
- console output mixed with the simulation loop;
- simple argument handling;
- a minimal `CMakeLists.txt`;
- no tests, library boundary, API documentation, installation, or package
  manifest.

The program should work for ordinary inputs. Its shortcomings should arise
from realistic proof-of-concept growth: mixed responsibilities, scattered
configuration, implicit assumptions, difficult-to-substitute dependencies,
and expensive changes.


### Requirements introduced during the course

- Add uniform, random, and single-cell initial conditions.
- Add periodic and fixed boundary conditions.
- Add fixed-generation and cycle-detection stopping conditions.
- Support console visualization and quiet execution.
- Collect activity and cycle statistics.
- Write results and configuration metadata.
- Support a small parameter sweep as an optional extension.

Each requirement should create a reason for a refactoring. Do not insert a
pattern before the requirement makes its value visible.


### Staged evolution

| Stage | Pressure | Resulting improvement |
|---|---|---|
| 0. Proof of concept | Demonstrate the experiment | One executable and minimal CMake |
| 1. Characterize behaviour | Changes may break working results | Known-generation and boundary tests |
| 2. Separate kernel and shell | Tests should not run the CLI or capture output | `ca_core` library plus application |
| 3. Establish variation points | Initialization, boundaries, and stopping vary | Injected callables or small Strategy interfaces |
| 4. Add quality gates | Boundary defects and undefined behaviour are possible | Warnings, analysis, ASan, and UBSan |
| 5. Support new output | Diagnostics should not modify the kernel | Observer/Decorator and output adapters |
| 6. Manage dependencies | Test and CLI dependencies must be reproducible | Manifest, pinned dependencies, and presets |
| 7. Document and deploy | Others must build and use the program | API docs, usage guide, install rules, and packaging |
| 8. Refactor safely | A new capability must not destabilize the core | Prepared architecture capstone |

The existing Cellular Automata implementation is closer to an intermediate or
final state than to the starting point. Reuse its ideas, but do not treat every
existing abstraction as mandatory. The final application should remain the
simplest design that supports the stated requirements.

Use one authoritative linear evolution where practical. Named Git tags or
commits can identify major teaching stages, for example:

```text
ca-poc
ca-characterized
ca-core-library
ca-tested
ca-analysed
ca-extensible
ca-packaged
```

Slides can show focused diffs between stages. Optional laboratories should
receive a stable starter snapshot, progressive checkpoints, and a clearly
separated reference solution.


## Later complementary exercise: particle-trajectory analysis

After the cellular-automaton course is stable, consider a particle-trajectory
analysis application as an alternative or advanced self-study exercise.

It could read observations containing particle identifier, time, and position;
validate and group them into trajectories; filter tracks; calculate a supplied
metric; and write per-particle and aggregate results.

This example would be particularly useful for:

- Adapter-based input and output formats;
- data-processing pipelines;
- testable readers and writers;
- configuration-driven filters and analysis strategies;
- realistic malformed-input handling;
- dependency management for parsing and serialization libraries.

The numerical calculation and acceptance criteria must be supplied so the
exercise does not repeat *Trustworthy Numerical Computing*. Do not begin this
exercise until the main cellular-automaton path, laboratories, and delivery
formats are complete and validated.


## Step-by-step plan of action


### Phase 1: confirm scope and ownership

- [ ] Approve the three-course responsibility boundary.
- [ ] Confirm whether CI is owned by this course or the version control course.
- [ ] Update the stated prerequisites to include basic CMake and the relevant
      *Scientific C++* topics.
- [ ] Define separate learning outcomes for the four-hour core and the optional
      practical modules.
- [ ] Record the no-bring-your-own-project policy in trainer guidance.


### Phase 2: audit and consolidate existing material

- [ ] Inventory every slide and example that links from this repository into
      `Scientific-C-plus-plus`.
- [ ] Compare both repositories' Builder, Factory, Strategy, error-handling,
      CMake, Conan, vcpkg, and CPM examples.
- [ ] Select one authoritative version of each duplicated example.
- [ ] Decide which historical examples should be retained as optional material
      and which should be replaced by links.
- [ ] Check all incoming links before moving or removing anything.


### Phase 3: establish the running example

- [ ] Write a short domain description and functional specification for the
      cellular-automaton experiment.
- [ ] Define representative inputs and exact expected outputs for small cases.
- [ ] Create the single-file proof-of-concept baseline.
- [ ] Confirm that the baseline is realistic, readable, and correct for normal
      inputs without already being well architected.
- [ ] Identify authentic boundary cases and defects for the testing and
      sanitizer demonstrations.
- [ ] Decide whether teaching stages will be represented by tags, commits,
      maintained snapshots, or a combination.


### Phase 4: migrate and simplify the existing CA material

- [ ] Move or port the Cellular Automata example into this repository.
- [ ] Preserve useful behaviour, documentation, and history from the existing
      implementation.
- [ ] Remove or simplify abstractions that are not justified by the training
      requirements.
- [ ] Separate the pure transition kernel from application orchestration.
- [ ] Create a reusable `ca_core` target and a thin executable target.
- [ ] Add deterministic unit, component, and application tests.
- [ ] Add warnings, static-analysis configuration, ASan, and UBSan.


### Phase 5: implement the architectural evolution

- [ ] Add initialization and boundary variation through the smallest suitable
      Strategy or callable abstractions.
- [ ] Keep object construction at an explicit application composition boundary.
- [ ] Add Factory logic only when configuration-driven selection requires it.
- [ ] Add observers or decorators for output, statistics, timing, or tracing.
- [ ] Add an Adapter or Facade around a genuine external concern.
- [ ] Add one focused non-memory RAII microexample if the running example does
      not naturally provide one.
- [ ] Document why each abstraction exists and what simpler alternative was
      considered.


### Phase 6: make the example buildable and deployable

- [ ] Select one primary package-manager workflow for the hands-on material.
- [ ] Treat other package managers as comparisons or optional references.
- [ ] Add reproducible runtime and test dependencies.
- [ ] Add CMake configure, build, test, and analysis presets.
- [ ] Add install rules and verify an installation from a clean build tree.
- [ ] Add API documentation and a concise user guide.
- [ ] Add a single documented command or workflow for build, test, and
      analysis.


### Phase 7: revise the curriculum

- [ ] Remove ranges and general functional-programming material from the
      learning outcomes, schedule, and slides.
- [ ] Replace basic CMake instruction with production-oriented CMake.
- [ ] Replace generic exception instruction with error-policy and
      exception-safety guidance.
- [ ] Integrate sanitizers with the static-analysis section.
- [ ] Replace the pattern catalogue with requirement-driven evolution of the
      running example.
- [ ] Add Adapter/Facade and scientific RAII coverage.
- [ ] Turn CRTP, variants, concepts, and type erasure into a design-choice
      comparison that references *Scientific C++*.
- [ ] Align the public learning outcomes with what the four-hour core can
      achieve without exercises.


### Phase 8: create optional laboratories

- [ ] Create the two-hour tooling laboratory with a stable starter and
      automated checkpoints.
- [ ] Create the two-hour architecture/refactoring laboratory using the same
      running example.
- [ ] Provide progressive hints that do not require individual trainer
      intervention.
- [ ] Provide reference solutions and explanations of the trade-offs.
- [ ] Verify that each laboratory works both trainer-led and self-paced.
- [ ] Provide an independent post-course project-assessment checklist without
      promising live project review.


### Phase 9: validate the complete training

- [ ] Build and test every maintained stage in a clean supported environment.
- [ ] Verify dependency installation from the documented instructions.
- [ ] Run repository-wide link and path checks after moving material.
- [ ] Check that no numerical-validity lesson duplicates *Trustworthy
      Numerical Computing*.
- [ ] Check that no language-mechanism lesson duplicates *Scientific C++*.
- [ ] Dry-run and time the four-hour seminar.
- [ ] Dry-run and time both optional two-hour laboratories.
- [ ] Pilot the material with participants who did not help develop it.
- [ ] Record common problems and turn them into documentation, hints, or
      automated checks.


### Phase 10: consider the complementary trajectory exercise

- [ ] Reassess demand after the cellular-automaton path has been delivered.
- [ ] Define a small trajectory data format and supplied scientific
      requirements.
- [ ] Emphasize pipeline, Adapter, and I/O architecture rather than numerical
      validation.
- [ ] Build it as an advanced or self-study exercise, not as a second mandatory
      running example.


## Definition of done

The redesign is complete when:

- the public course boundary and prerequisites are explicit;
- the four-hour core is coherent without mandatory participant exercises;
- both optional laboratories are self-contained and scalable for one trainer;
- the cellular automaton evolves from a credible proof of concept into a
  tested, documented, maintainable, and deployable application;
- patterns are motivated by requirements and not accumulated for their own
  sake;
- duplicated examples have a single authoritative owner;
- all slides, documentation, examples, and commands agree;
- clean builds, tests, analysis, installation, and link checks pass;
- the four-, six-, and eight-hour delivery formats have been timed and tested.


## Open decisions

- Which package manager should be used in the primary hands-on workflow?
- Which CLI or configuration dependency should the final application use?
- Should the course repository use tagged commits, maintained stage
  directories, or both for the example evolution?
- Does the version control training already cover CI sufficiently?
- Should PIMPL remain visible in the core comparison or become optional
  reading only?
- Which patterns should be implemented in the prepared capstone rather than
  demonstrated by the trainer?
